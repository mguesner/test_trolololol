#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdio.h>

char *signaux[] =
{
    [0] = "NONE",
    [1] = "SIGHUP",
    [2] = "SIGINT",
    [3] = "SIGQUIT",
    [4] = "SIGILL",
    [5] = "SIGTRAP",
    [6] = "SIGABRT",
    [7] = "SIGBUS",
    [8] = "SIGFPE",
    [9] = "SIGKILL",
    [10] = "SIGUSR1",
    [11] = "SIGSEGV",
    [12] = "SIGUSR2",
    [13] = "SIGPIPE",
    [14] = "SIGALRM",
    [15] = "SIGTERM",
    [16] = "SIGSTKFLT",
    [17] = "SIGCHLD",
    [18] = "SIGCONT",
    [19] = "SIGSTOP",
    [20] = "SIGTSTP",
    [21] = "SIGTTIN",
    [22] = "SIGTTOU",
    [23] = "SIGURG",
    [24] = "SIGXCPU",
    [25] = "SIGXFSZ",
    [26] = "SIGVTALRM",
    [27] = "SIGPROF",
    [28] = "SIGWINCH",
    [29] = "SIGIO",
    [30] = "SIGPWR",
    [31] = "SIGSYS"
};

int wait_for_syscall(int child, int sig, int *status, sigset_t set1, sigset_t set2)
{
    ptrace(PTRACE_SYSCALL, child, 0, sig);
    sigprocmask(SIG_SETMASK, &set1, 0);
    waitpid(child, status, 0);
    sigprocmask(SIG_BLOCK, &set2, 0);
    if (WIFSTOPPED(*status) && WSTOPSIG(*status) & 0x80)
        return 0;
    if (WIFEXITED(*status) || WIFSIGNALED(*status))
        return -1;
    siginfo_t siginfo;
    ptrace(PTRACE_GETSIGINFO, child, 0, &siginfo);
    if (WSTOPSIG(*status) == SIGILL || WSTOPSIG(*status) == SIGSEGV || WSTOPSIG(*status) == SIGBUS
        || WSTOPSIG(*status) == SIGFPE || WSTOPSIG(*status) == SIGSEGV)
        fprintf(stderr, "--- %s {si_signo=%s, si_code=%d, si_addr=%p} ---\n", signaux[WSTOPSIG(*status)]
            , signaux[siginfo.si_signo], siginfo.si_code, siginfo.si_addr);
    else if (siginfo.si_code == SI_USER)
        fprintf(stderr, "--- %s {si_signo=%s, si_code=%d, si_pid=%d, si_uid=%d} ---\n", signaux[WSTOPSIG(*status)]
            , signaux[siginfo.si_signo], siginfo.si_code, siginfo.si_pid, siginfo.si_uid);
    else if (siginfo.si_code == SI_QUEUE || siginfo.si_code == SI_TIMER
        || siginfo.si_code == SI_ASYNCIO || siginfo.si_code == SI_MESGQ)
        fprintf(stderr, "--- %s {si_signo=%s, si_code=%d, si_pid=%d, si_uid=%d, si_value={sival_int=%d, sival_ptr=%p} ---\n", signaux[WSTOPSIG(*status)]
            , signaux[siginfo.si_signo], siginfo.si_code, siginfo.si_pid, siginfo.si_uid, siginfo.si_value.sival_int, siginfo.si_value.sival_ptr);
    else if (WSTOPSIG(*status) == SIGCHLD)
        fprintf(stderr, "--- %s {si_signo=%s, si_code=%d, si_pid=%d, si_uid=%d, si_status=%d} ---\n", signaux[WSTOPSIG(*status)]
            , signaux[siginfo.si_signo], siginfo.si_code, siginfo.si_pid, siginfo.si_uid, siginfo.si_status);
    else if (WSTOPSIG(*status) == SIGIO)
        fprintf(stderr, "--- %s {si_signo=%s, si_code=%d, si_band=%d} ---\n", signaux[WSTOPSIG(*status)]
            , signaux[siginfo.si_signo], siginfo.si_code, (int)siginfo.si_band);
    else
    	fprintf(stderr, "--- %s {si_signo=%s, si_code=%d} ---\n", signaux[WSTOPSIG(*status)]
            , signaux[siginfo.si_signo], siginfo.si_code);
    return WSTOPSIG(*status);
}