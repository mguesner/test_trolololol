#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdio.h>

int wait_for_syscall(int child, int sig)
{
    int status;
    while (1) {
        ptrace(PTRACE_SYSCALL, child, 0, sig);
        waitpid(child, &status, 0);
        if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
            return 0;
        if (WIFEXITED(status))
            return -1;
        fprintf(stderr, "[stopped %d (%x)]\n", status, WSTOPSIG(status));
        return WSTOPSIG(status);
    }
}