#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/resource.h>
#include "ft_strace.h"

extern struct syscall_entry syscalls[];

void maj_list(t_list_begin *list, int syscall, int chrono)
{
	t_list *it;
	it = list->begin;
	while (it)
	{
		if (it->syscall == syscall)
			break ;
		it = it->next;
	}
	if (it)
	{
		it->seconds += (float)chrono / 1000000.;
	}
	else
	{
		it = malloc(sizeof (t_list));
		it->seconds = (float)chrono / 1000000.;
		it->syscall = syscall;
		it->next = NULL;
		if (list->end)
		{
			list->end->next = it;
			list->end = it;
		}
		else
		{
			list->begin = it;
			list->end = it;
		}
	}
}

void do_father_c(int child)
{
	int status;	
	sigset_t set1;
	sigset_t set2;
	sigemptyset(&set1);
	sigemptyset(&set2);
	sigaddset(&set2, SIGHUP);
	sigaddset(&set2, SIGINT);
	sigaddset(&set2, SIGQUIT);
	sigaddset(&set2, SIGPIPE);
	sigaddset(&set2, SIGTERM);
	waitpid(child, &status, WUNTRACED);
	// a modifier
	if (!WIFSTOPPED(status))
		exit(-1);
	ptrace(PTRACE_SEIZE, child, 0, 0);
	ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
	int sig = 0;
	// struct timeval tv_before;
	// struct timeval tv_after;
		struct rusage rusage;
	t_list_begin list;
	bzero(&list, sizeof(t_list_begin));
	while (1)
	{
		ptrace(PTRACE_SYSCALL, child, 0, sig);
		sigprocmask(SIG_SETMASK, &set1, 0);
		wait4(child, &status, 0, &rusage);
		sigprocmask(SIG_BLOCK, &set2, 0);
		if (WIFEXITED(status) || WIFSIGNALED(status))
			break ;
		if (!(WIFSTOPPED(status) && WSTOPSIG(status) & 0x80))
		{
			sig = WSTOPSIG(status);
			continue;
		}
		t_regs regs = get_regs(child);
		int chrono = rusage.ru_stime.tv_usec;
		sigprocmask(SIG_SETMASK, &set1, 0);
		ptrace(PTRACE_SYSCALL, child, 0, sig);
		// gettimeofday(&tv_before,NULL);
		wait4(child, &status, 0, &rusage);
		// gettimeofday(&tv_after,NULL);
		sigprocmask(SIG_BLOCK, &set2, 0);
		if (WIFEXITED(status) || WIFSIGNALED(status))
			break ;
		chrono = rusage.ru_stime.tv_usec - chrono;
		maj_list(&list, regs.orig_rax, chrono);
	}
	t_list *it = list.begin;
	while (it)
	{
		printf("%f\t\t%s\n", it->seconds, syscalls[it->syscall].name);
		it = it->next;
	}
}