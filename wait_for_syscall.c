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
        if (WSTOPSIG(*status) == SIGILL || WSTOPSIG(*status) == SIGSEGV || WSTOPSIG(*status) == SIGBUS
            || WSTOPSIG(*status) == SIGFPE || WSTOPSIG(*status) == SIGSEGV)
            fprintf(stderr, "--- %d {si_signo=%d, si_code=%d, si_addr=%p} ---\n", WSTOPSIG(*status)
                , siginfo.si_signo, siginfo.si_code, siginfo.si_addr);
        else if (siginfo.si_code == SI_USER)
            fprintf(stderr, "--- %d {si_signo=%d, si_code=%d, si_pid=%d, si_uid=%d} ---\n", WSTOPSIG(*status)
                , siginfo.si_signo, siginfo.si_code, siginfo.si_pid, siginfo.si_uid);
        else if (siginfo.si_code == SI_QUEUE || siginfo.si_code == SI_TIMER
            || siginfo.si_code == SI_ASYNCIO || siginfo.si_code == SI_MESGQ)
            fprintf(stderr, "--- %d {si_signo=%d, si_code=%d, si_pid=%d, si_uid=%d, si_value={sival_int=%d, sival_ptr=%p} ---\n", WSTOPSIG(*status)
                , siginfo.si_signo, siginfo.si_code, siginfo.si_pid, siginfo.si_uid, siginfo.si_value.sival_int, siginfo.si_value.sival_ptr);
        else if (WSTOPSIG(*status) == SIGCHLD)
            fprintf(stderr, "--- %d {si_signo=%d, si_code=%d, si_pid=%d, si_uid=%d, si_status=%d} ---\n", WSTOPSIG(*status)
                , siginfo.si_signo, siginfo.si_code, siginfo.si_pid, siginfo.si_uid, siginfo.si_status);
        else if (WSTOPSIG(*status) == SIGIO)
            fprintf(stderr, "--- %d {si_signo=%d, si_code=%d, si_band=%d} ---\n", WSTOPSIG(*status)
                , siginfo.si_signo, siginfo.si_code, (int)siginfo.si_band);
        return WSTOPSIG(*status);
    }
}