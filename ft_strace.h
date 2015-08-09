#ifndef FT_STRACE_H
#define FT_STRACE_H

#include <sys/user.h>

enum ret_type
{
	TYPE_NONE,
	TYPE_PTR,
	TYPE_STRING,
	TYPE_VALUE
};

struct syscall_entry
{
	char *name;
	int nargs;
	enum ret_type rtype;
};

typedef struct user_regs_struct t_regs;

void	do_child(int argc, char **argv);
void	ft_error(char *msg, int error);
void	do_father(int child);
int		wait_for_syscall(int child, int ret, int *status);
struct syscall_entry	show_syscall(int child);
t_regs	get_regs(int child);
long	get_arg(t_regs regs, int num);
void	pre_exec(int child);
char	*read_string(pid_t child, long addr);
char *read_string_tab(int child, long addr);

#endif