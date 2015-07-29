#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "ft_strace.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		return -1;
	int child = fork();
	if (child < 0)
    {
        int error = errno;
        perror("fork");
		return error;
    }
	else if (!child)
        do_child(argc - 1, argv + 1);
	else
        do_father(child);
    return 0;
}

// SYSCALL
// GETREGSET
// SETOPTIONS
// GETSIGINFO
// SEIZE
// INTERUPT
// LISTEN