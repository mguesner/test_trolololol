#ifndef SYSCALLENV_H
#define SYSCALLENV_H

struct syscall_entry syscalls[] = {
	[0] = {
		.name = "read",
		.nargs = 3,
		.rtype = 3},
	[1] = {
		.name = "write",
		.nargs = 3,
		.rtype = 3},
	[2] = {
		.name = "open",
		.nargs = 3,
		.rtype = 3},
	[3] = {
		.name = "close",
		.nargs = 1,
		.rtype = 3},
	[4] = {
		.name = "stat",
		.nargs = 3,
		.rtype = 3},
	[5] = {
		.name = "fstat",
		.nargs = 2,
		.rtype = 3},
	[6] = {
		.name = "lstat",
		.nargs = 3,
		.rtype = 3},
	[7] = {
		.name = "poll",
		.nargs = 3,
		.rtype = 3},
	[8] = {
		.name = "lseek",
		.nargs = 3,
		.rtype = 3},
	[9] = {
		.name = "mmap",
		.nargs = 6,
		.rtype = 1},
	[10] = {
		.name = "mprotect",
		.nargs = 3,
		.rtype = 3},
	[11] = {
		.name = "munmap",
		.nargs = 2,
		.rtype = 3},
	[12] = {
		.name = "brk",
		.nargs = 1,
		.rtype = 3},
	[13] = {
		.name = "rt_sigaction",
		.nargs = 4 ,
		.rtype = 0},
	[14] = {
		.name = "rt_sigprocmask",
		.nargs = 4,
		.rtype = 0},
	[15] = {
		.name = "rt_sigreturn",
		.nargs = -1,
		.rtype = 0},
	[16] = {
		.name = "ioctl",
		.nargs = 3,
		.rtype = 3},
	[17] = {
		.name = "pread64",
		.nargs = 4,
		.rtype = 3},
	[18] = {
		.name = "pwrite64",
		.nargs = 4,
		.rtype = 3},
	[19] = {
		.name = "readv",
		.nargs = 3,
		.rtype = 3},
	[20] = {
		.name = "writev",
		.nargs = 3,
		.rtype = 3},
	[21] = {
		.name = "access",
		.nargs = 2,
		.rtype = 3},
	[22] = {
		.name = "pipe",
		.nargs = 1,
		.rtype = 3},
	[23] = {
		.name = "select",
		.nargs = 5,
		.rtype = 3},
	[24] = {
		.name = "sched_yield",
		.nargs = 0,
		.rtype = 3},
	[25] = {
		.name = "mremap",
		.nargs = 5,
		.rtype = 1},
	[26] = {
		.name = "msync",
		.nargs = 3,
		.rtype = 3},
	[27] = {
		.name = "mincore",
		.nargs = 3,
		.rtype = 3},
	[28] = {
		.name = "madvise",
		.nargs = 3,
		.rtype = 3},
	[29] = {
		.name = "shmget",
		.nargs = 3,
		.rtype = 3},
	[30] = {
		.name = "shmat",
		.nargs = 3,
		.rtype = 1},
	[31] = {
		.name = "shmctl",
		.nargs = 3,
		.rtype = 3},
	[32] = {
		.name = "dup",
		.nargs = 1,
		.rtype = 3},
	[33] = {
		.name = "dup2",
		.nargs = 2,
		.rtype = 3},
	[34] = {
		.name = "pause",
		.nargs = 0,
		.rtype = 3},
	[35] = {
		.name = "nanosleep",
		.nargs = 2,
		.rtype = 3},
	[36] = {
		.name = "getitimer",
		.nargs = 2,
		.rtype = 3},
	[37] = {
		.name = "alarm",
		.nargs = 1,
		.rtype = 3},
	[38] = {
		.name = "setitimer",
		.nargs = 3,
		.rtype = 3},
	[39] = {
		.name = "getpid",
		.nargs = 0,
		.rtype = 3},
	[40] = {
		.name = "sendfile",
		.nargs = 4,
		.rtype = 3},
	[41] = {
		.name = "socket",
		.nargs = 3,
		.rtype = 3},
	[42] = {
		.name = "connect",
		.nargs = 3,
		.rtype = 3},
	[43] = {
		.name = "accept",
		.nargs = 3,
		.rtype = 3},
	[44] = {
		.name = "sendto",
		.nargs = 6,
		.rtype = 3},
	[45] = {
		.name = "recvfrom",
		.nargs = 6,
		.rtype = 3},
	[46] = {
		.name = "sendmsg",
		.nargs = 3,
		.rtype = 3},
	[47] = {
		.name = "recvmsg",
		.nargs = 3,
		.rtype = 3},
	[48] = {
		.name = "shutdown",
		.nargs = 2,
		.rtype = 3},
	[49] = {
		.name = "bind",
		.nargs = 3,
		.rtype = 3},
	[50] = {
		.name = "listen",
		.nargs = 2,
		.rtype = 3},
	[51] = {
		.name = "getsockname",
		.nargs = 3,
		.rtype = 3},
	[52] = {
		.name = "getpeername",
		.nargs = 3,
		.rtype = 3},
	[53] = {
		.name = "socketpair",
		.nargs = 4,
		.rtype = 3},
	[54] = {
		.name = "setsockopt",
		.nargs = 5,
		.rtype = 3},
	[55] = {
		.name = "getsockopt",
		.nargs = 5,
		.rtype = 3},
	[56] = {
		.name = "clone",
		.nargs = 5,
		.rtype = 3},
	[57] = {
		.name = "fork",
		.nargs = 0,
		.rtype = 3},
	[58] = {
		.name = "vfork",
		.nargs = 0,
		.rtype = 3},
	[59] = {
		.name = "execve",
		.nargs = 4,
		.rtype = 3},
	[60] = {
		.name = "exit",
		.nargs = 1,
		.rtype = 3},
	[61] = {
		.name = "wait4",
		.nargs = 4,
		.rtype = 3},
	[62] = {
		.name = "kill",
		.nargs = 2,
		.rtype = 3},
	[63] = {
		.name = "uname",
		.nargs = 1,
		.rtype = 3},
	[64] = {
		.name = "semget",
		.nargs = 3,
		.rtype = 3},
	[65] = {
		.name = "semop",
		.nargs = 3,
		.rtype = 3},
	[66] = {
		.name = "semctl",
		.nargs = 4,
		.rtype = 3},
	[67] = {
		.name = "shmdt",
		.nargs = 1,
		.rtype = 3},
	[68] = {
		.name = "msgget",
		.nargs = 2,
		.rtype = 3},
	[69] = {
		.name = "msgsnd",
		.nargs = 4,
		.rtype = 3},
	[70] = {
		.name = "msgrcv",
		.nargs = 5,
		.rtype = 3},
	[71] = {
		.name = "msgctl",
		.nargs = 3,
		.rtype = 3},
	[72] = {
		.name = "fcntl",
		.nargs = 3,
		.rtype = 3},
	[73] = {
		.name = "flock",
		.nargs = 2,
		.rtype = 3},
	[74] = {
		.name = "fsync",
		.nargs = 1,
		.rtype = 3},
	[75] = {
		.name = "fdatasync",
		.nargs = 1,
		.rtype = 3},
	[76] = {
		.name = "truncate",
		.nargs = 2,
		.rtype = 3},
	[77] = {
		.name = "ftruncate",
		.nargs = 2,
		.rtype = 3},
	[78] = {
		.name = "getdents",
		.nargs = 3,
		.rtype = 3},
	[79] = {
		.name = "getcwd",
		.nargs = 2,
		.rtype = 2},
	[80] = {
		.name = "chdir",
		.nargs = 1,
		.rtype = 3},
	[81] = {
		.name = "fchdir",
		.nargs = 1,
		.rtype = 3},
	[82] = {
		.name = "rename",
		.nargs = 2,
		.rtype = 3},
	[83] = {
		.name = "mkdir",
		.nargs = 2,
		.rtype = 3},
	[84] = {
		.name = "rmdir",
		.nargs = 1,
		.rtype = 3},
	[85] = {
		.name = "creat",
		.nargs = 2,
		.rtype = 3},
	[86] = {
		.name = "link",
		.nargs = 3,
		.rtype = 3},
	[87] = {
		.name = "unlink",
		.nargs = 1,
		.rtype = 3},
	[88] = {
		.name = "symlink",
		.nargs = 3,
		.rtype = 3},
	[89] = {
		.name = "readlink",
		.nargs = 4,
		.rtype = 3},
	[90] = {
		.name = "chmod",
		.nargs = 2,
		.rtype = 3},
	[91] = {
		.name = "fchmod",
		.nargs = 2,
		.rtype = 3},
	[92] = {
		.name = "chown",
		.nargs = 3,
		.rtype = 3},
	[93] = {
		.name = "fchown",
		.nargs = 3,
		.rtype = 3},
	[94] = {
		.name = "lchown",
		.nargs = 3,
		.rtype = 3},
	[95] = {
		.name = "umask",
		.nargs = 1,
		.rtype = 3},
	[96] = {
		.name = "gettimeofday",
		.nargs = 2,
		.rtype = 3},
	[97] = {
		.name = "getrlimit",
		.nargs = 2,
		.rtype = 3},
	[98] = {
		.name = "getrusage",
		.nargs = 2,
		.rtype = 3},
	[99] = {
		.name = "sysinfo",
		.nargs = 1,
		.rtype = 3},
	[100] = {
		.name = "times",
		.nargs = 1,
		.rtype = 3},
	[101] = {
		.name = "ptrace",
		.nargs = 2,
		.rtype = 3},
	[102] = {
		.name = "getuid",
		.nargs = 0,
		.rtype = 3},
	[103] = {
		.name = "syslog",
		.nargs = 5,
		.rtype = 3},
	[104] = {
		.name = "getgid",
		.nargs = 0,
		.rtype = 3},
	[105] = {
		.name = "setuid",
		.nargs = 1,
		.rtype = 3},
	[106] = {
		.name = "setgid",
		.nargs = 1,
		.rtype = 3},
	[107] = {
		.name = "geteuid",
		.nargs = 0,
		.rtype = 3},
	[108] = {
		.name = "getegid",
		.nargs = 0,
		.rtype = 3},
	[109] = {
		.name = "setpgid",
		.nargs = 2,
		.rtype = 3},
	[110] = {
		.name = "getppid",
		.nargs = 0,
		.rtype = 3},
	[111] = {
		.name = "getpgrp",
		.nargs = 0,
		.rtype = 3},
	[112] = {
		.name = "setsid",
		.nargs = 0,
		.rtype = 3},
	[113] = {
		.name = "setreuid",
		.nargs = 2,
		.rtype = 3},
	[114] = {
		.name = "setregid",
		.nargs = 2,
		.rtype = 3},
	[115] = {
		.name = "getgroups",
		.nargs = 2,
		.rtype = 3},
	[116] = {
		.name = "setgroups",
		.nargs = 2,
		.rtype = 3},
	[117] = {
		.name = "setresuid",
		.nargs = 3,
		.rtype = 3},
	[118] = {
		.name = "getresuid",
		.nargs = 3,
		.rtype = 3},
	[119] = {
		.name = "setresgid",
		.nargs = 3,
		.rtype = 3},
	[120] = {
		.name = "getresgid",
		.nargs = 3,
		.rtype = 3},
	[121] = {
		.name = "getpgid",
		.nargs = 1,
		.rtype = 3},
	[122] = {
		.name = "setfsuid",
		.nargs = 1,
		.rtype = 3},
	[123] = {
		.name = "setfsgid",
		.nargs = 1,
		.rtype = 3},
	[124] = {
		.name = "getsid",
		.nargs = 1,
		.rtype = 3},
	[125] = {
		.name = "capget",
		.nargs = -1,
		.rtype = 0},
	[126] = {
		.name = "capset",
		.nargs = -1,
		.rtype = 0},
	[127] = {
		.name = "rt_sigpending",
		.nargs = -1,
		.rtype = 0},
	[128] = {
		.name = "rt_sigtimedwait",
		.nargs = -1,
		.rtype = 0},
	[129] = {
		.name = "rt_sigqueueinfo",
		.nargs = -1,
		.rtype = 0},
	[130] = {
		.name = "rt_sigsuspend",
		.nargs = -1,
		.rtype = 0},
	[131] = {
		.name = "sigaltstack",
		.nargs = 2,
		.rtype = 3},
	[132] = {
		.name = "utime",
		.nargs = 2,
		.rtype = 3},
	[133] = {
		.name = "mknod",
		.nargs = 3,
		.rtype = 3},
	[134] = {
		.name = "uselib",
		.nargs = -1,
		.rtype = 0},
	[135] = {
		.name = "personality",
		.nargs = 1,
		.rtype = 3},
	[136] = {
		.name = "ustat",
		.nargs = 2,
		.rtype = 3},
	[137] = {
		.name = "statfs",
		.nargs = 3,
		.rtype = 3},
	[138] = {
		.name = "fstatfs",
		.nargs = 2,
		.rtype = 3},
	[139] = {
		.name = "sysfs",
		.nargs = -1,
		.rtype = 0},
	[140] = {
		.name = "getpriority",
		.nargs = 2,
		.rtype = 3},
	[141] = {
		.name = "setpriority",
		.nargs = 3,
		.rtype = 3},
	[142] = {
		.name = "sched_setparam",
		.nargs = 2,
		.rtype = 3},
	[143] = {
		.name = "sched_getparam",
		.nargs = 2,
		.rtype = 3},
	[144] = {
		.name = "sched_setscheduler",
		.nargs = 3,
		.rtype = 3},
	[145] = {
		.name = "sched_getscheduler",
		.nargs = 1,
		.rtype = 3},
	[146] = {
		.name = "sched_get_priority_max",
		.nargs = 1,
		.rtype = 3},
	[147] = {
		.name = "sched_get_priority_min",
		.nargs = 1,
		.rtype = 3},
	[148] = {
		.name = "sched_rr_get_interval",
		.nargs = 2,
		.rtype = 3},
	[149] = {
		.name = "mlock",
		.nargs = 2,
		.rtype = 3},
	[150] = {
		.name = "munlock",
		.nargs = 2,
		.rtype = 3},
	[151] = {
		.name = "mlockall",
		.nargs = 1,
		.rtype = 3},
	[152] = {
		.name = "munlockall",
		.nargs = 0,
		.rtype = 3},
	[153] = {
		.name = "vhangup",
		.nargs = 0,
		.rtype = 3},
	[154] = {
		.name = "modify_ldt",
		.nargs = -1,
		.rtype = 0},
	[155] = {
		.name = "pivot_root",
		.nargs = -1,
		.rtype = 0},
	[156] = {
		.name = "_sysctl",
		.nargs = -1,
		.rtype = 0},
	[157] = {
		.name = "prctl",
		.nargs = 2,
		.rtype = 3},		
	[158] = {
		.name = "arch_prctl",
		.nargs = 2,
		.rtype = 3},
	[159] = {
		.name = "adjtimex",
		.nargs = 1,
		.rtype = 3},
	[160] = {
		.name = "setrlimit",
		.nargs = 2,
		.rtype = 3},
	[161] = {
		.name = "chroot",
		.nargs = 1,
		.rtype = 3},
	[162] = {
		.name = "sync",
		.nargs = 0,
		.rtype = 3},
	[163] = {
		.name = "acct",
		.nargs = 1,
		.rtype = 3},
	[164] = {
		.name = "settimeofday",
		.nargs = 2,
		.rtype = 3},
	[165] = {
		.name = "mount",
		.nargs = 5,
		.rtype = 3},
	[166] = {
		.name = "umount2",
		.nargs = 2,
		.rtype = 3},
	[167] = {
		.name = "swapon",
		.nargs = 2,
		.rtype = 3},
	[168] = {
		.name = "swapoff",
		.nargs = 1,
		.rtype = 3},
	[169] = {
		.name = "reboot",
		.nargs = 1,
		.rtype = 3},
	[170] = {
		.name = "sethostname",
		.nargs = 2,
		.rtype = 3},
	[171] = {
		.name = "setdomainname",
		.nargs = 2,
		.rtype = 3},
	[172] = {
		.name = "iopl",
		.nargs = 1,
		.rtype = 3},
	[173] = {
		.name = "ioperm",
		.nargs = 3,
		.rtype = 3},
	[174] = {
		.name = "create_module",
		.nargs = -1,
		.rtype = 0},
	[175] = {
		.name = "init_module",
		.nargs = -1,
		.rtype = 0},
	[176] = {
		.name = "delete_module",
		.nargs = -1,
		.rtype = 0},
	[177] = {
		.name = "get_kernel_syms",
		.nargs = -1,
		.rtype = 0},
	[178] = {
		.name = "query_module",
		.nargs = -1,
		.rtype = 0},
	[179] = {
		.name = "quotactl",
		.nargs = 4,
		.rtype = 3},
	[180] = {
		.name = "nfsservctl",
		.nargs = -1,
		.rtype = 0},
	[181] = {
		.name = "getpmsg",
		.nargs = 5,
		.rtype = 3},
	[182] = {
		.name = "putpmsg",
		.nargs = 5,
		.rtype = 3},
	[183] = {
		.name = "afs_syscall",
		.nargs = -1,
		.rtype = 0},
	[184] = {
		.name = "tuxcall",
		.nargs = -1,
		.rtype = 0},
	[185] = {
		.name = "security",
		.nargs = -1,
		.rtype = 0},
	[186] = {
		.name = "gettid",
		.nargs = -1,
		.rtype = 0},
	[187] = {
		.name = "readahead",
		.nargs = 3,
		.rtype = 3},
	[188] = {
		.name = "setxattr",
		.nargs = 5,
		.rtype = 3},
	[189] = {
		.name = "lsetxattr",
		.nargs = 5,
		.rtype = 3},
	[190] = {
		.name = "fsetxattr",
		.nargs = 5,
		.rtype = 3},
	[191] = {
		.name = "getxattr",
		.nargs = 4,
		.rtype = 3},
	[192] = {
		.name = "lgetxattr",
		.nargs = 4,
		.rtype = 3},
	[193] = {
		.name = "fgetxattr",
		.nargs = 4,
		.rtype = 3},
	[194] = {
		.name = "listxattr",
		.nargs = 3,
		.rtype = 3},
	[195] = {
		.name = "llistxattr",
		.nargs = 3,
		.rtype = 3},
	[196] = {
		.name = "flistxattr",
		.nargs = 3,
		.rtype = 3},
	[197] = {
		.name = "removexattr",
		.nargs = 2,
		.rtype = 3},
	[198] = {
		.name = "lremovexattr",
		.nargs = 2,
		.rtype = 3},
	[199] = {
		.name = "fremovexattr",
		.nargs = 2,
		.rtype = 3},
	[200] = {
		.name = "tkill",
		.nargs = -1,
		.rtype = 0},
	[201] = {
		.name = "time",
		.nargs = 1,
		.rtype = 3},
	[202] = {
		.name = "futex",
		.nargs = -1,
		.rtype = 0},
	[203] = {
		.name = "sched_setaffinity",
		.nargs = 3,
		.rtype = 3},
	[204] = {
		.name = "sched_getaffinity",
		.nargs = 3,
		.rtype = 3},
	[205] = {
		.name = "set_thread_area",
		.nargs = -1,
		.rtype = 0},
	[206] = {
		.name = "io_setup",
		.nargs = -1,
		.rtype = 0},
	[207] = {
		.name = "io_destroy",
		.nargs = -1,
		.rtype = 0},
	[208] = {
		.name = "io_getevents",
		.nargs = -1,
		.rtype = 0},
	[209] = {
		.name = "io_submit",
		.nargs = -1,
		.rtype = 0},
	[210] = {
		.name = "io_cancel",
		.nargs = -1,
		.rtype = 0},
	[211] = {
		.name = "get_thread_area",
		.nargs = -1,
		.rtype = 0},
	[212] = {
		.name = "lookup_dcookie",
		.nargs = -1,
		.rtype = 0},
	[213] = {
		.name = "epoll_create",
		.nargs = 1,
		.rtype = 3},
	[214] = {
		.name = "epoll_ctl_old",
		.nargs = -1,
		.rtype = 0},
	[215] = {
		.name = "epoll_wait_old",
		.nargs = -1,
		.rtype = 0},
	[216] = {
		.name = "remap_file_pages",
		.nargs = 5,
		.rtype = 3},
	[217] = {
		.name = "getdents64",
		.nargs = -1,
		.rtype = 0},
	[218] = {
		.name = "set_tid_address",
		.nargs = 1,
		.rtype = 0},
	[219] = {
		.name = "restart_syscall",
		.nargs = -1,
		.rtype = 0},
	[220] = {
		.name = "semtimedop",
		.nargs = 4,
		.rtype = 3},
	[221] = {
		.name = "fadvise64",
		.nargs = -1,
		.rtype = 0},
	[222] = {
		.name = "timer_create",
		.nargs = 3,
		.rtype = 3},
	[223] = {
		.name = "timer_settime",
		.nargs = 4,
		.rtype = 3},
	[224] = {
		.name = "timer_gettime",
		.nargs = 2,
		.rtype = 3},
	[225] = {
		.name = "timer_getoverrun",
		.nargs = 1,
		.rtype = 3},
	[226] = {
		.name = "timer_delete",
		.nargs = 1,
		.rtype = 3},
	[227] = {
		.name = "clock_settime",
		.nargs = 2,
		.rtype = 3},
	[228] = {
		.name = "clock_gettime",
		.nargs = 2,
		.rtype = 3},
	[229] = {
		.name = "clock_getres",
		.nargs = 2,
		.rtype = 3},
	[230] = {
		.name = "clock_nanosleep",
		.nargs = 4,
		.rtype = 3},
	[231] = {
		.name = "exit_group",
		.nargs = 1,
		.rtype = 0},
	[232] = {
		.name = "epoll_wait",
		.nargs = 4,
		.rtype = 3},
	[233] = {
		.name = "epoll_ctl",
		.nargs = 4,
		.rtype = 3},
	[234] = {
		.name = "tgkill",
		.nargs = -1,
		.rtype = 0},
	[235] = {
		.name = "utimes",
		.nargs = 2,
		.rtype = 3},
	[236] = {
		.name = "vserver",
		.nargs = -1,
		.rtype = 0},
	[237] = {
		.name = "mbind",
		.nargs = -1,
		.rtype = 0},
	[238] = {
		.name = "set_mempolicy",
		.nargs = -1,
		.rtype = 0},
	[239] = {
		.name = "get_mempolicy",
		.nargs = -1,
		.rtype = 0},
	[240] = {
		.name = "mq_open",
		.nargs = 3,
		.rtype = 3},
	[241] = {
		.name = "mq_unlink",
		.nargs = 1,
		.rtype = 3},
	[242] = {
		.name = "mq_timedsend",
		.nargs = 6,
		.rtype = 3},
	[243] = {
		.name = "mq_timedreceive",
		.nargs = 6,
		.rtype = 3},
	[244] = {
		.name = "mq_notify",
		.nargs = 2,
		.rtype = 3},
	[245] = {
		.name = "mq_getsetattr",
		.nargs = -1,
		.rtype = 0},
	[246] = {
		.name = "kexec_load",
		.nargs = -1,
		.rtype = 0},
	[247] = {
		.name = "waitid",
		.nargs = 4,
		.rtype = 3},
	[248] = {
		.name = "add_key",
		.nargs = -1,
		.rtype = 0},
	[249] = {
		.name = "request_key",
		.nargs = -1,
		.rtype = 0},
	[250] = {
		.name = "keyctl",
		.nargs = -1,
		.rtype = 0},
	[251] = {
		.name = "ioprio_set",
		.nargs = -1,
		.rtype = 0},
	[252] = {
		.name = "ioprio_get",
		.nargs = -1,
		.rtype = 0},
	[253] = {
		.name = "inotify_init",
		.nargs = 0,
		.rtype = 3},
	[254] = {
		.name = "inotify_add_watch",
		.nargs = 3,
		.rtype = 3},
	[255] = {
		.name = "inotify_rm_watch",
		.nargs = 2,
		.rtype = 3},
	[256] = {
		.name = "migrate_pages",
		.nargs = -1,
		.rtype = 0},
	[257] = {
		.name = "openat",
		.nargs = 4,
		.rtype = 3},
	[258] = {
		.name = "mkdirat",
		.nargs = 3,
		.rtype = 3},
	[259] = {
		.name = "mknodat",
		.nargs = 4,
		.rtype = 3},
	[260] = {
		.name = "fchownat",
		.nargs = 5,
		.rtype = 3},
	[261] = {
		.name = "futimesat",
		.nargs = 3,
		.rtype = 3},
	[262] = {
		.name = "newfstatat",
		.nargs = -1,
		.rtype = 0},
	[263] = {
		.name = "unlinkat",
		.nargs = 3,
		.rtype = 3},
	[264] = {
		.name = "renameat",
		.nargs = 4,
		.rtype = 3},
	[265] = {
		.name = "linkat",
		.nargs = 6,
		.rtype = 3},
	[266] = {
		.name = "symlinkat",
		.nargs = 4,
		.rtype = 3},
	[267] = {
		.name = "readlinkat",
		.nargs = 5,
		.rtype = 3},
	[268] = {
		.name = "fchmodat",
		.nargs = 4,
		.rtype = 3},
	[269] = {
		.name = "faccessat",
		.nargs = 4,
		.rtype = 3},
	[270] = {
		.name = "pselect6",
		.nargs = -1,
		.rtype = 0},
	[271] = {
		.name = "ppoll",
		.nargs = 4,
		.rtype = 3},
	[272] = {
		.name = "unshare",
		.nargs = 1,
		.rtype = 3},
	[273] = {
		.name = "set_robust_list",
		.nargs = 2,
		.rtype = 0},
	[274] = {
		.name = "get_robust_list",
		.nargs = -1,
		.rtype = 0},
	[275] = {
		.name = "splice",
		.nargs = 6,
		.rtype = 3},
	[276] = {
		.name = "tee",
		.nargs = 4,
		.rtype = 3},
	[277] = {
		.name = "sync_file_range",
		.nargs = 4,
		.rtype = 3},
	[278] = {
		.name = "vmsplice",
		.nargs = 4,
		.rtype = 3},
	[279] = {
		.name = "move_pages",
		.nargs = -1,
		.rtype = 0},
	[280] = {
		.name = "utimensat",
		.nargs = 4,
		.rtype = 3},
	[281] = {
		.name = "epoll_pwait",
		.nargs = 5,
		.rtype = 3},
	[282] = {
		.name = "signalfd",
		.nargs = 3,
		.rtype = 3},
	[283] = {
		.name = "timerfd_create",
		.nargs = 2,
		.rtype = 3},
	[284] = {
		.name = "eventfd",
		.nargs = 2,
		.rtype = 3},
	[285] = {
		.name = "fallocate",
		.nargs = 4,
		.rtype = 3},
	[286] = {
		.name = "timerfd_settime",
		.nargs = 4,
		.rtype = 3},
	[287] = {
		.name = "timerfd_gettime",
		.nargs = 2,
		.rtype = 3},
	[288] = {
		.name = "accept4",
		.nargs = 4,
		.rtype = 3},
	[289] = {
		.name = "signalfd4",
		.nargs = -1,
		.rtype = 0},
	[290] = {
		.name = "eventfd2",
		.nargs = -1,
		.rtype = 0},
	[291] = {
		.name = "epoll_create1",
		.nargs = 1,
		.rtype = 3},
	[292] = {
		.name = "dup3",
		.nargs = 3,
		.rtype = 3},
	[293] = {
		.name = "pipe2",
		.nargs = 2,
		.rtype = 3},
	[294] = {
		.name = "inotify_init1",
		.nargs = 1,
		.rtype = 3},
	[295] = {
		.name = "preadv",
		.nargs = 4,
		.rtype = 3},
	[296] = {
		.name = "pwritev",
		.nargs = 4,
		.rtype = 3},
	[297] = {
		.name = "rt_tgsigqueueinfo",
		.nargs = -1,
		.rtype = 0},
	[298] = {
		.name = "perf_event_open",
		.nargs = -1,
		.rtype = 0},
	[299] = {
		.name = "recvmmsg",
		.nargs = 5,
		.rtype = 3},
	[300] = {
		.name = "fanotify_init",
		.nargs = 2,
		.rtype = 3},
	[301] = {
		.name = "fanotify_mark",
		.nargs = 5,
		.rtype = 3},
	[302] = {
		.name = "prlimit64",
		.nargs = 4,
		.rtype = 3},
	[303] = {
		.name = "name_to_handle_at",
		.nargs = 5,
		.rtype = 3},
	[304] = {
		.name = "open_by_handle_at",
		.nargs = 3,
		.rtype = 3},
	[305] = {
		.name = "clock_adjtime",
		.nargs = 2,
		.rtype = 3},
	[306] = {
		.name = "syncfs",
		.nargs = 1,
		.rtype = 3},
	[307] = {
		.name = "sendmmsg",
		.nargs = 4,
		.rtype = 3},
	[308] = {
		.name = "setns",
		.nargs = 2,
		.rtype = 3},
	[309] = {
		.name = "getcpu",
		.nargs = -1,
		.rtype = 0},
	[310] = {
		.name = "process_vm_readv",
		.nargs = 6,
		.rtype = 3},
	[311] = {
		.name = "process_vm_writev",
		.nargs = 6,
		.rtype = 3},
	[312] = {
		.name = "kcmp",
		.nargs = -1,
		.rtype = 0},
	[313] = {
		.name = "finit_module",
		.nargs = -1,
		.rtype = 0},
	[314] = {
		.name = "sched_setattr",
		.nargs = -1,
		.rtype = 0},
	[315] = {
		.name = "sched_getattr",
		.nargs = -1,
		.rtype = 0},
	[316] = {
		.name = "renameat2",
		.nargs = -1,
		.rtype = 0},
	[317] = {
		.name = "seccomp",
		.nargs = -1,
		.rtype = 0},
};

#endif
