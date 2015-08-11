#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "ft_strace.h"

int main(int argc, char **argv)
{
	int push = 1;
	if (argc < 2)
		return -1;
	if (!strcmp(argv[1], "-c"))
		push++;
	int child = fork();
	if (child < 0)
    {
        int error = errno;
        perror("fork");
		return error;
    }
	else if (!child)
        do_child(argc - push, argv + push);
	else if (push == 1)
        do_father(child);
    else
    	do_father_c(child);
    return 0;
}

// SYSCALL
// GETREGSET
// SETOPTIONS
// GETSIGINFO
// SEIZE
// INTERUPT
// LISTEN