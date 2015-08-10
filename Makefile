NAME = ft_strace

OBJ = main.o\
	  do_child.o\
	  ft_error.o\
	  do_father.o\
	  wait_for_syscall.o\
	  show_syscall.o\
	  get_reg.o\
	  get_arg.o\
	  pre_exec.o\
	  read_string.o\
	  read_string_tab.o\
	  init_sig.o\


CC = clang -g -O3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all