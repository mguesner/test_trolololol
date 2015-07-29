#include <sys/ptrace.h>
#include <stdio.h>
#include <sys/user.h>
#include "ft_strace.h"

t_regs get_regs(int child)
{
	struct user_regs_struct regs;
	if (ptrace( PTRACE_GETREGS, child, NULL, &regs ) == -1)
	// long val = ptrace(PTRACE_PEEKUSER, child, off);
	perror("ptrace(PTRACE_PEEKUSER");

	//TODO: gerer erreur
    //assert(errno == 0);
    return regs;
}