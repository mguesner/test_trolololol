#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "ft_strace.h"

void do_father(int child)
{
	int status;
	sigset_t set1;
	sigset_t set2;
	waitpid(child, &status, WUNTRACED);
	sigemptyset(&set1);
	sigemptyset(&set2);
	sigaddset(&set2, SIGHUP);
	sigaddset(&set2, SIGINT);
	sigaddset(&set2, SIGQUIT);
	sigaddset(&set2, SIGPIPE);
	sigaddset(&set2, SIGTERM);
	// a modifier
	assert(WIFSTOPPED(status));
	ptrace(PTRACE_SEIZE, child, 0, 0);
	ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
	pre_exec(child);
	int ret = 0;
	while (1)
	{
		if ((ret = wait_for_syscall(child, ret, &status)) == -1)
			break;
		else if (ret > 0)
			continue;
        sigprocmask(SIG_BLOCK, &set2, 0);
		struct syscall_entry syscall = show_syscall(child);
        sigprocmask(SIG_SETMASK, &set1, 0);
		if ((ret = wait_for_syscall(child, ret, &status) == -1))
		{
			fprintf(stderr, ") = ?\n");
			break;
		}
		else if (ret > 0)
			continue;
        sigprocmask(SIG_BLOCK, &set2, 0);
		t_regs regs = get_regs(child);
		if (regs.rax >= -(unsigned long long)4095)
		{
			int err = -regs.rax;
			fprintf(stderr, ") = %d  %d %s\n", -1, err, strerror(err));
		}
		else
		{
			if (syscall.rtype == TYPE_STRING)
				fprintf(stderr, ") = %s\n",(char *)regs.rax);
			else if (syscall.rtype == TYPE_PTR)
				fprintf(stderr, ") = %p\n",(void *)regs.rax);
			else
				fprintf(stderr, ") = %llu\n",regs.rax);
		}
        sigprocmask(SIG_SETMASK, &set1, 0);
	}
	if (WIFEXITED(status))
		fprintf(stderr, "+++ exited with %d +++\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		fprintf(stderr, "+++ killed by %d +++\n", WTERMSIG(status));
}