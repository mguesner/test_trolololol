#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdio.h>
#include <assert.h>
#include "ft_strace.h"

void do_father(int child)
{
	int status;
	printf("waiting...\n");
	waitpid(child, &status, WUNTRACED);
	printf("signal recieve\n");
	// a modifier
	assert(WIFSTOPPED(status));
	ptrace(PTRACE_SEIZE, child, 0, 0);
	ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
	printf("option done\n");
	int ret = 0;
	while (1) {
		if ((ret = wait_for_syscall(child, ret, &status)) == -1)
			break;
		else if (ret > 0)
			continue;
		struct syscall_entry syscall = show_syscall(child);
		if ((ret = wait_for_syscall(child, ret, &status) == -1))
		{
			fprintf(stderr, ") = ?\n");
			break;
		}
		else if (ret > 0)
			continue;
		t_regs regs = get_regs(child);
		if (regs.rax >= -(unsigned long long)4095)
			fprintf(stderr, ") = %d  %llu\n", -1, -regs.rax);
		else
		{
			if (syscall.rtype == TYPE_STRING)
				fprintf(stderr, ") = %s\n",(char *)regs.rax);
			else if (syscall.rtype == TYPE_PTR)
				fprintf(stderr, ") = %p\n",(void *)regs.rax);
			else
				fprintf(stderr, ") = %llu\n",regs.rax);
		}
	}
	if (WIFEXITED(status))
		fprintf(stderr, "+++ exited with %d +++\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		fprintf(stderr, "+++ killed by %d +++\n", WTERMSIG(status));
}