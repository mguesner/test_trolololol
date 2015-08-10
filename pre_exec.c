#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_strace.h"

void pre_exec(int child, sigset_t set1, sigset_t set2)
{
	int status;
	int ret = 0;
	while (1)
	{
		if ((ret = wait_for_syscall(child, ret, &status, set1, set2)) == -1)
			break;
		t_regs regs = get_regs(child);
		char *arg1 = read_string(child, get_arg(regs, 0));
		char *arg2 = read_string_tab(child, get_arg(regs, 1));
		char *arg3 = read_string_tab(child, get_arg(regs, 2));
		if (regs.orig_rax != 59)
		{
			ptrace(PTRACE_CONT, child, 0, 0);
			waitpid(child, &status, 0);
			exit(0);
		}
		// fprintf(stderr, "banane\n");
		if ((ret = wait_for_syscall(child, ret, &status, set1 , set2)) == -1)
			break;
		t_regs regs2 = get_regs(child);
		if (regs2.rax == 0)
		{
			fprintf(stderr, "execve(\"%s\", [%s], [%s]) = %llu\n", arg1
				, arg2, arg3, regs2.rax);
			free(arg1);
			break;
		}
		free(arg1);
	}
}