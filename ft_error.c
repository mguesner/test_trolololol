#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void	ft_error(char *msg, int error)
{
	char *tmp_msg = malloc(strlen(msg) + 11);
	sprintf(tmp_msg, "ft_strace: %s", msg);
	errno = error;
	perror(tmp_msg);
	exit(error);
}