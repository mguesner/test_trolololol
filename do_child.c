#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "ft_strace.h"

void	do_child(int argc, char **argv)
{
	char *args [argc+1];
    for (int i=0;i<argc;i++)
        args[i] = argv[i];
    args[argc] = NULL;
	kill(getpid(), SIGSTOP);
	execvp(args[0], args);
	int error = errno;
	char *msg = malloc(11 + strlen(args[0]));
	sprintf(msg, "Can't stat %s", args[0]);
	ft_error(msg, error);
}