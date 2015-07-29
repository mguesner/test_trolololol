#include "ft_strace.h"
#include <stdio.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <stdlib.h>
#include <sys/ptrace.h>

void	show_syscall(int child)
{
	// ptrace(PTRACE_LISTEN, 0, 0);
	t_regs regs = get_regs(child);
	printf("%llu()=", regs.orig_rax);
}