#include "ft_strace.h"
#include <stdio.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include "syscallenv.h"

struct syscall_entry	show_syscall(int child)
{
	// ptrace(PTRACE_LISTEN, 0, 0);
	t_regs regs = get_regs(child);
	struct syscall_entry syscall = syscalls[regs.orig_rax];
	fprintf(stderr, "%s(", syscall.name);
	// for (int i = 0; i < syscall.nargs; ++i)
	// 	printf("%ld%s", get_arg(regs, i), i == syscall.nargs - 1 ? "" : ", ");
	return syscall;
}