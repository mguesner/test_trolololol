#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

static void	handler(int sig)
{
	(void)sig;
	// printf("banane\n");
}

void	init_sig(sigset_t *set1, sigset_t *set2)
{
	struct sigaction sig;
	sigemptyset(set1);
	sigemptyset(set2);
	sigaddset(set2, SIGHUP);
	sigaddset(set2, SIGINT);
	sigaddset(set2, SIGQUIT);
	sigaddset(set2, SIGPIPE);
	sigaddset(set2, SIGTERM);
	sig.sa_handler = handler;
	sigaction(SIGINT, &sig, 0);
}