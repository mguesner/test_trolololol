#include <stdlib.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

int wait_for_syscall(pid_t child) {
    int status;
    while (1) {
        ptrace(PTRACE_SYSCALL, child, 0, 0);
        waitpid(child, &status, 0);
        if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
            return 0;
        if (WIFEXITED(status))
            return 1;
        fprintf(stderr, "[stopped %d (%x)]\n", status, WSTOPSIG(status));
    }
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return -1;
	int child = fork();
	if (child < 0)
		return -1;
	else if (!child)
	{
		kill(getpid(), SIGSTOP);
		printf("launch exec\n");
		system(argv[0]);
	}
	else
	{
		int status;
		waitpid(child, &status, 0);
    	assert(WIFSTOPPED(status));
    	ptrace(PTRACE_SEIZE,child, 0, 0);
    	ptrace(PTRACE_LISTEN,child, 0, 0);
    	ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
    	while(1) {
        if (wait_for_syscall(child) != 0)
            break;
        if (wait_for_syscall(child) != 0)
            break;
        // fprintf(stderr, "%d\n", retval);
    }
    return 0;
	}
}

// SYSCALL
// GETREGSET
// SETOPTIONS
// GETSIGINFO
// SEIZE
// INTERUPT
// LISTEN