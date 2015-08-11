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

void maj_list(t_list_begin *list, int syscall, int chrono, int error)
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
		it->calls++;
		if (error)
			it->errors++;
	}
	else
	{
		it = malloc(sizeof (t_list));
		it->seconds = (float)chrono / 1000000.;
		it->syscall = syscall;
		it->calls = 1;
		it->errors = error;
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
	float total = 0;
	int total_calls = 0;
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
		regs = get_regs(child);
		int error = 0;
		if (regs.rax >= -(unsigned long long)4095)
			error = 1;
		chrono = rusage.ru_stime.tv_usec - chrono;
		total += chrono;
		maj_list(&list, regs.orig_rax, chrono, error);
		total_calls++;
	}
	total  = total / 1000000;
	fprintf(stderr, "%% time     seconds  usecs/call     calls    errors syscall\n------ ----------- ----------- --------- --------- ----------------\n");
	t_list *it = list.begin;
	while (it)
	{
		fprintf(stderr, "%6.2f %11f %11d %9d %9d %s\n", it->seconds  / total * 100, it->seconds, (int)(it->seconds / it->calls * 1000000), it->calls, it->errors, syscalls[it->syscall].name);
		it = it->next;
	}
	fprintf(stderr, "------ ----------- ----------- --------- --------- ----------------\n%6.2f %11f             %9d        11 total\n", 100., total, total_calls);
}