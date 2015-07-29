#ifndef FT_STRACE_H
#define FT_STRACE_H

#include <sys/user.h>

typedef struct user_regs_struct t_regs;

void	do_child(int argc, char **argv);
void	ft_error(char *msg, int error);
void	do_father(int child);
int		wait_for_syscall(int child);
void	show_syscall(int child);
t_regs	get_regs(int child);

#endif