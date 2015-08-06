#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdio.h>

int wait_for_syscall(int child, int sig, int *status)
{
    while (1) {
        ptrace(PTRACE_SYSCALL, child, 0, sig);
        waitpid(child, status, 0);
        if (WIFSTOPPED(*status) && WSTOPSIG(*status) & 0x80)
            return 0;
        if (WIFEXITED(*status) || WIFSIGNALED(*status))
            return -1;
        siginfo_t siginfo;
        ptrace(PTRACE_GETSIGINFO, child, 0, &siginfo);
        fprintf(stderr, "--- %d {si_signo=%d, si_code=%d, si_pid=%d, si_uid=%d} ---\n", WSTOPSIG(*status)
            , siginfo.si_signo, siginfo.si_code, siginfo.si_pid, siginfo.si_uid);
        return WSTOPSIG(*status);
    }
}