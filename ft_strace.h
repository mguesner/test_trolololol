#ifndef FT_STRACE_H
#define FT_STRACE_H

#include <sys/user.h>
#include <signal.h>

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

typedef struct 		s_list
{
	float prc_time;
	float seconds;
	int usecs_per_call;
	int calls;
	int errors;
	int syscall;
	struct s_list *next;	
}					t_list;

typedef struct 		s_list_begin
{
	t_list *begin;
	t_list *end;
	int size;
}					t_list_begin;

typedef struct user_regs_struct t_regs;

void	do_child(int argc, char **argv);
void	ft_error(char *msg, int error);
void	do_father(int child);
int		wait_for_syscall(int child, int ret, int *status, sigset_t set1, sigset_t set2);
struct syscall_entry	show_syscall(int child);
t_regs	get_regs(int child);
long	get_arg(t_regs regs, int num);
void	pre_exec(int child, sigset_t set1, sigset_t set2);
char	*read_string(pid_t child, long addr);
char 	*read_string_tab(int child, long addr);
void	init_sig(sigset_t *set1, sigset_t *set2);
void	do_father_c(int child);

#endif