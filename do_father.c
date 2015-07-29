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
	ptrace(PTRACE_SEIZE,child, 0, 0);
	ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
	printf("option done\n");
	while(1) {
		if (wait_for_syscall(child) != 0)
			break;
		show_syscall(child);
		if (wait_for_syscall(child) != 0)
			break;
		t_regs regs = get_regs(child);
		printf("%llu\n", regs.rax);
	}
}