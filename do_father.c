#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "ft_strace.h"

extern char *signaux[32];

void do_father(int child)
{
	int status;	
	sigset_t set1;
	sigset_t set2;
	waitpid(child, &status, WUNTRACED);
	// a modifier
	if (!WIFSTOPPED(status))
		exit(-1);
	init_sig(&set1, &set2);
	ptrace(PTRACE_SEIZE, child, 0, 0);
	ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
	pre_exec(child, set1, set2);
	int ret = 0;
	while (1)
	{
		if ((ret = wait_for_syscall(child, ret, &status, set1, set2)) == -1)
			break;
		else if (ret > 0)
			continue;
		struct syscall_entry syscall = show_syscall(child);
		if ((ret = wait_for_syscall(child, ret, &status, set1, set2) == -1))
		{
			fprintf(stderr, ") = ?\n");
			break;
		}
		else if (ret > 0)
			continue;
		t_regs regs = get_regs(child);
		if (regs.rax >= -(unsigned long long)4095)
		{
			int err = -regs.rax;
			fprintf(stderr, ") = %d  %d %s\n", -1, err, strerror(err));
		}
		else
		{
			if (syscall.rtype == TYPE_PTR || syscall.rtype == TYPE_STRING)
				fprintf(stderr, ") = %p\n",(void *)regs.rax);
			else
				fprintf(stderr, ") = %llu\n",regs.rax);
		}
	}
	if (WIFEXITED(status))
		fprintf(stderr, "+++ exited with %d +++\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		fprintf(stderr, "+++ killed by %s +++\n", signaux[WTERMSIG(status)]);
}