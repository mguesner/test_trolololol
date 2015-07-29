#ifndef SYSCALLENV_H
#define SYSCALLENV_H
struct syscall_entry syscalls[] = {
	[0] = {
		.name = "read",
		.nargs = 3}
	[1] = {
		.name = "write",
		.nargs = 3}
	[2] = {
		.name = "open",
		.nargs = 3}
	[3] = {
		.name = "close",
		.nargs = 1}
	[4] = {
		.name = "stat",
		.nargs = 2}
	[5] = {
		.name = "fstat",
		.nargs = 2}
	[6] = {
		.name = "lstat",
		.nargs = 2}
	[7] = {
		.name = "poll",
		.nargs = 3}
	[8] = {
		.name = "lseek",
		.nargs = 3}
	[9] = {
		.name = "mmap",
		.nargs = 0}
	[10] = {
		.name = "mprotect",
		.nargs = 3}
	[11] = {
		.name = "munmap",
		.nargs = 2}
	[12] = {
		.name = "brk",
		.nargs = 1}
	[13] = {
		.name = "rt_sigaction",
		.nargs = 4}
	[14] = {
		.name = "rt_sigprocmask",
		.nargs = 4}
	[15] = {
		.name = "rt_sigreturn",
		.nargs = 0}
	[16] = {
		.name = "ioctl",
		.nargs = 3}
	[17] = {
		.name = "pread64",
		.nargs = 4}
	[18] = {
		.name = "pwrite64",
		.nargs = 4}
	[19] = {
		.name = "readv",
		.nargs = 3}
	[20] = {
		.name = "writev",
		.nargs = 3}
	[21] = {
		.name = "access",
		.nargs = 2}
	[22] = {
		.name = "pipe",
		.nargs = 1}
	[23] = {
		.name = "select",
		.nargs = 5}
	[24] = {
		.name = "sched_yield",
		.nargs = 1}
	[25] = {
		.name = "mremap",
		.nargs = 5}
	[26] = {
		.name = "msync",
		.nargs = 3}
	[27] = {
		.name = "mincore",
		.nargs = 3}
	[28] = {
		.name = "madvise",
		.nargs = 3}
	[29] = {
		.name = "shmget",
		.nargs = 3}
	[30] = {
		.name = "shmat",
		.nargs = 3}
	[31] = {
		.name = "shmctl",
		.nargs = 3}
	[32] = {
		.name = "dup",
		.nargs = 1}
	[33] = {
		.name = "dup2",
		.nargs = 2}
	[34] = {
		.name = "pause",
		.nargs = 1}
	[35] = {
		.name = "nanosleep",
		.nargs = 2}
	[36] = {
		.name = "getitimer",
		.nargs = 2}
	[37] = {
		.name = "alarm",
		.nargs = 1}
	[38] = {
		.name = "setitimer",
		.nargs = 3}
	[39] = {
		.name = "getpid",
		.nargs = 1}
	[40] = {
		.name = "sendfile",
		.nargs = 4}
	[41] = {
		.name = "socket",
		.nargs = 3}
	[42] = {
		.name = "connect",
		.nargs = 3}
	[43] = {
		.name = "accept",
		.nargs = 3}
	[44] = {
		.name = "sendto",
		.nargs = 6}
	[45] = {
		.name = "recvfrom",
		.nargs = 6}
	[46] = {
		.name = "sendmsg",
		.nargs = 3}
	[47] = {
		.name = "recvmsg",
		.nargs = 3}
	[48] = {
		.name = "shutdown",
		.nargs = 2}
	[49] = {
		.name = "bind",
		.nargs = 3}
	[50] = {
		.name = "listen",
		.nargs = 2}
	[51] = {
		.name = "getsockname",
		.nargs = 3}
	[52] = {
		.name = "getpeername",
		.nargs = 3}
	[53] = {
		.name = "socketpair",
		.nargs = 4}
	[54] = {
		.name = "setsockopt",
		.nargs = 5}
	[55] = {
		.name = "getsockopt",
		.nargs = 5}
	[56] = {
		.name = "clone",
		.nargs = 5}
	[57] = {
		.name = "fork",
		.nargs = 1}
	[58] = {
		.name = "vfork",
		.nargs = 1}
	[59] = {
		.name = "execve",
		.nargs = 3}
	[60] = {
		.name = "exit",
		.nargs = 1}
	[61] = {
		.name = "wait4",
		.nargs = 4}
	[62] = {
		.name = "kill",
		.nargs = 2}
	[63] = {
		.name = "uname",
		.nargs = 1}
	[64] = {
		.name = "semget",
		.nargs = 3}
	[65] = {
		.name = "semop",
		.nargs = 3}
	[66] = {
		.name = "semctl",
		.nargs = 4}
	[67] = {
		.name = "shmdt",
		.nargs = 1}
	[68] = {
		.name = "msgget",
		.nargs = 2}
	[69] = {
		.name = "msgsnd",
		.nargs = 4}
	[70] = {
		.name = "msgrcv",
		.nargs = 5}
	[71] = {
		.name = "msgctl",
		.nargs = 3}
	[72] = {
		.name = "fcntl",
		.nargs = 3}
	[73] = {
		.name = "flock",
		.nargs = 2}
	[74] = {
		.name = "fsync",
		.nargs = 1}
	[75] = {
		.name = "fdatasync",
		.nargs = 1}
	[76] = {
		.name = "truncate",
		.nargs = 2}
	[77] = {
		.name = "ftruncate",
		.nargs = 2}
	[78] = {
		.name = "getdents",
		.nargs = 3}
	[79] = {
		.name = "getcwd",
		.nargs = 2}
	[80] = {
		.name = "chdir",
		.nargs = 1}
	[81] = {
		.name = "fchdir",
		.nargs = 1}
	[82] = {
		.name = "rename",
		.nargs = 2}
	[83] = {
		.name = "mkdir",
		.nargs = 2}
	[84] = {
		.name = "rmdir",
		.nargs = 1}
	[85] = {
		.name = "creat",
		.nargs = 2}
	[86] = {
		.name = "link",
		.nargs = 2}
	[87] = {
		.name = "unlink",
		.nargs = 1}
	[88] = {
		.name = "symlink",
		.nargs = 2}
	[89] = {
		.name = "readlink",
		.nargs = 3}
	[90] = {
		.name = "chmod",
		.nargs = 2}
	[91] = {
		.name = "fchmod",
		.nargs = 2}
	[92] = {
		.name = "chown",
		.nargs = 3}
	[93] = {
		.name = "fchown",
		.nargs = 3}
	[94] = {
		.name = "lchown",
		.nargs = 3}
	[95] = {
		.name = "umask",
		.nargs = 1}
	[96] = {
		.name = "gettimeofday",
		.nargs = 2}
	[97] = {
		.name = "getrlimit",
		.nargs = 2}
	[98] = {
		.name = "getrusage",
		.nargs = 2}
	[99] = {
		.name = "sysinfo",
		.nargs = 1}
	[100] = {
		.name = "times",
		.nargs = 1}
	[101] = {
		.name = "ptrace",
		.nargs = 4}
	[102] = {
		.name = "getuid",
		.nargs = 1}
	[103] = {
		.name = "syslog",
		.nargs = 3}
	[104] = {
		.name = "getgid",
		.nargs = 1}
	[105] = {
		.name = "setuid",
		.nargs = 1}
	[106] = {
		.name = "setgid",
		.nargs = 1}
	[107] = {
		.name = "geteuid",
		.nargs = 1}
	[108] = {
		.name = "getegid",
		.nargs = 1}
	[109] = {
		.name = "setpgid",
		.nargs = 2}
	[110] = {
		.name = "getppid",
		.nargs = 1}
	[111] = {
		.name = "getpgrp",
		.nargs = 1}
	[112] = {
		.name = "setsid",
		.nargs = 1}
	[113] = {
		.name = "setreuid",
		.nargs = 2}
	[114] = {
		.name = "setregid",
		.nargs = 2}
	[115] = {
		.name = "getgroups",
		.nargs = 2}
	[116] = {
		.name = "setgroups",
		.nargs = 2}
	[117] = {
		.name = "setresuid",
		.nargs = 3}
	[118] = {
		.name = "getresuid",
		.nargs = 3}
	[119] = {
		.name = "setresgid",
		.nargs = 3}
	[120] = {
		.name = "getresgid",
		.nargs = 3}
	[121] = {
		.name = "getpgid",
		.nargs = 1}
	[122] = {
		.name = "setfsuid",
		.nargs = 1}
	[123] = {
		.name = "setfsgid",
		.nargs = 1}
	[124] = {
		.name = "getsid",
		.nargs = 1}
	[125] = {
		.name = "capget",
		.nargs = 2}
	[126] = {
		.name = "capset",
		.nargs = 2}
	[127] = {
		.name = "rt_sigpending",
		.nargs = 2}
	[128] = {
		.name = "rt_sigtimedwait",
		.nargs = 4}
	[129] = {
		.name = "rt_sigqueueinfo",
		.nargs = 3}
	[130] = {
		.name = "rt_sigsuspend",
		.nargs = 2}
	[131] = {
		.name = "sigaltstack",
		.nargs = 2}
	[132] = {
		.name = "utime",
		.nargs = 2}
	[133] = {
		.name = "mknod",
		.nargs = 3}
	[134] = {
		.name = "uselib",
		.nargs = 1}
	[135] = {
		.name = "personality",
		.nargs = 1}
	[136] = {
		.name = "ustat",
		.nargs = 2}
	[137] = {
		.name = "statfs",
		.nargs = 2}
	[138] = {
		.name = "fstatfs",
		.nargs = 2}
	[139] = {
		.name = "sysfs",
		.nargs = 3}
	[140] = {
		.name = "getpriority",
		.nargs = 2}
	[141] = {
		.name = "setpriority",
		.nargs = 3}
	[142] = {
		.name = "sched_setparam",
		.nargs = 2}
	[143] = {
		.name = "sched_getparam",
		.nargs = 2}
	[144] = {
		.name = "sched_setscheduler",
		.nargs = 3}
	[145] = {
		.name = "sched_getscheduler",
		.nargs = 1}
	[146] = {
		.name = "sched_get_priority_max",
		.nargs = 1}
	[147] = {
		.name = "sched_get_priority_min",
		.nargs = 1}
	[148] = {
		.name = "sched_rr_get_interval",
		.nargs = 2}
	[149] = {
		.name = "mlock",
		.nargs = 2}
	[150] = {
		.name = "munlock",
		.nargs = 2}
	[151] = {
		.name = "mlockall",
		.nargs = 1}
	[152] = {
		.name = "munlockall",
		.nargs = 1}
	[153] = {
		.name = "vhangup",
		.nargs = 1}
	[154] = {
		.name = "modify_ldt",
		.nargs = 0}
	[155] = {
		.name = "pivot_root",
		.nargs = 2}
	[156] = {
		.name = "_sysctl",
		.nargs = 0}
	[157] = {
		.name = "prctl",
		.nargs = 5}
	[158] = {
		.name = "arch_prctl",
		.nargs = 0}
	[159] = {
		.name = "adjtimex",
		.nargs = 1}
	[160] = {
		.name = "setrlimit",
		.nargs = 2}
	[161] = {
		.name = "chroot",
		.nargs = 1}
	[162] = {
		.name = "sync",
		.nargs = 1}
	[163] = {
		.name = "acct",
		.nargs = 1}
	[164] = {
		.name = "settimeofday",
		.nargs = 2}
	[165] = {
		.name = "mount",
		.nargs = 5}
	[166] = {
		.name = "umount2",
		.nargs = 0}
	[167] = {
		.name = "swapon",
		.nargs = 2}
	[168] = {
		.name = "swapoff",
		.nargs = 1}
	[169] = {
		.name = "reboot",
		.nargs = 4}
	[170] = {
		.name = "sethostname",
		.nargs = 2}
	[171] = {
		.name = "setdomainname",
		.nargs = 2}
	[172] = {
		.name = "iopl",
		.nargs = 0}
	[173] = {
		.name = "ioperm",
		.nargs = 3}
	[174] = {
		.name = "create_module",
		.nargs = 0}
	[175] = {
		.name = "init_module",
		.nargs = 3}
	[176] = {
		.name = "delete_module",
		.nargs = 2}
	[177] = {
		.name = "get_kernel_syms",
		.nargs = 0}
	[178] = {
		.name = "query_module",
		.nargs = 0}
	[179] = {
		.name = "quotactl",
		.nargs = 4}
	[180] = {
		.name = "nfsservctl",
		.nargs = 0}
	[181] = {
		.name = "getpmsg",
		.nargs = 0}
	[182] = {
		.name = "putpmsg",
		.nargs = 0}
	[183] = {
		.name = "afs_syscall",
		.nargs = 0}
	[184] = {
		.name = "tuxcall",
		.nargs = 0}
	[185] = {
		.name = "security",
		.nargs = 0}
	[186] = {
		.name = "gettid",
		.nargs = 1}
	[187] = {
		.name = "readahead",
		.nargs = 3}
	[188] = {
		.name = "setxattr",
		.nargs = 5}
	[189] = {
		.name = "lsetxattr",
		.nargs = 5}
	[190] = {
		.name = "fsetxattr",
		.nargs = 5}
	[191] = {
		.name = "getxattr",
		.nargs = 4}
	[192] = {
		.name = "lgetxattr",
		.nargs = 4}
	[193] = {
		.name = "fgetxattr",
		.nargs = 4}
	[194] = {
		.name = "listxattr",
		.nargs = 3}
	[195] = {
		.name = "llistxattr",
		.nargs = 3}
	[196] = {
		.name = "flistxattr",
		.nargs = 3}
	[197] = {
		.name = "removexattr",
		.nargs = 2}
	[198] = {
		.name = "lremovexattr",
		.nargs = 2}
	[199] = {
		.name = "fremovexattr",
		.nargs = 2}
	[200] = {
		.name = "tkill",
		.nargs = 2}
	[201] = {
		.name = "time",
		.nargs = 1}
	[202] = {
		.name = "futex",
		.nargs = 6}
	[203] = {
		.name = "sched_setaffinity",
		.nargs = 3}
	[204] = {
		.name = "sched_getaffinity",
		.nargs = 3}
	[205] = {
		.name = "set_thread_area",
		.nargs = 0}
	[206] = {
		.name = "io_setup",
		.nargs = 2}
	[207] = {
		.name = "io_destroy",
		.nargs = 1}
	[208] = {
		.name = "io_getevents",
		.nargs = 5}
	[209] = {
		.name = "io_submit",
		.nargs = 3}
	[210] = {
		.name = "io_cancel",
		.nargs = 3}
	[211] = {
		.name = "get_thread_area",
		.nargs = 0}
	[212] = {
		.name = "lookup_dcookie",
		.nargs = 3}
	[213] = {
		.name = "epoll_create",
		.nargs = 1}
	[214] = {
		.name = "epoll_ctl_old",
		.nargs = 0}
	[215] = {
		.name = "epoll_wait_old",
		.nargs = 0}
	[216] = {
		.name = "remap_file_pages",
		.nargs = 5}
	[217] = {
		.name = "getdents64",
		.nargs = 3}
	[218] = {
		.name = "set_tid_address",
		.nargs = 1}
	[219] = {
		.name = "restart_syscall",
		.nargs = 1}
	[220] = {
		.name = "semtimedop",
		.nargs = 4}
	[221] = {
		.name = "fadvise64",
		.nargs = 4}
	[222] = {
		.name = "timer_create",
		.nargs = 3}
	[223] = {
		.name = "timer_settime",
		.nargs = 4}
	[224] = {
		.name = "timer_gettime",
		.nargs = 2}
	[225] = {
		.name = "timer_getoverrun",
		.nargs = 1}
	[226] = {
		.name = "timer_delete",
		.nargs = 1}
	[227] = {
		.name = "clock_settime",
		.nargs = 2}
	[228] = {
		.name = "clock_gettime",
		.nargs = 2}
	[229] = {
		.name = "clock_getres",
		.nargs = 2}
	[230] = {
		.name = "clock_nanosleep",
		.nargs = 4}
	[231] = {
		.name = "exit_group",
		.nargs = 1}
	[232] = {
		.name = "epoll_wait",
		.nargs = 4}
	[233] = {
		.name = "epoll_ctl",
		.nargs = 4}
	[234] = {
		.name = "tgkill",
		.nargs = 3}
	[235] = {
		.name = "utimes",
		.nargs = 2}
	[236] = {
		.name = "vserver",
		.nargs = 0}
	[237] = {
		.name = "mbind",
		.nargs = 6}
	[238] = {
		.name = "set_mempolicy",
		.nargs = 3}
	[239] = {
		.name = "get_mempolicy",
		.nargs = 5}
	[240] = {
		.name = "mq_open",
		.nargs = 4}
	[241] = {
		.name = "mq_unlink",
		.nargs = 1}
	[242] = {
		.name = "mq_timedsend",
		.nargs = 5}
	[243] = {
		.name = "mq_timedreceive",
		.nargs = 5}
	[244] = {
		.name = "mq_notify",
		.nargs = 2}
	[245] = {
		.name = "mq_getsetattr",
		.nargs = 3}
	[246] = {
		.name = "kexec_load",
		.nargs = 4}
	[247] = {
		.name = "waitid",
		.nargs = 5}
	[248] = {
		.name = "add_key",
		.nargs = 5}
	[249] = {
		.name = "request_key",
		.nargs = 4}
	[250] = {
		.name = "keyctl",
		.nargs = 5}
	[251] = {
		.name = "ioprio_set",
		.nargs = 3}
	[252] = {
		.name = "ioprio_get",
		.nargs = 2}
	[253] = {
		.name = "inotify_init",
		.nargs = 1}
	[254] = {
		.name = "inotify_add_watch",
		.nargs = 3}
	[255] = {
		.name = "inotify_rm_watch",
		.nargs = 2}
	[256] = {
		.name = "migrate_pages",
		.nargs = 4}
	[257] = {
		.name = "openat",
		.nargs = 4}
	[258] = {
		.name = "mkdirat",
		.nargs = 3}
	[259] = {
		.name = "mknodat",
		.nargs = 4}
	[260] = {
		.name = "fchownat",
		.nargs = 5}
	[261] = {
		.name = "futimesat",
		.nargs = 3}
	[262] = {
		.name = "newfstatat",
		.nargs = 4}
	[263] = {
		.name = "unlinkat",
		.nargs = 3}
	[264] = {
		.name = "renameat",
		.nargs = 4}
	[265] = {
		.name = "linkat",
		.nargs = 5}
	[266] = {
		.name = "symlinkat",
		.nargs = 3}
	[267] = {
		.name = "readlinkat",
		.nargs = 4}
	[268] = {
		.name = "fchmodat",
		.nargs = 3}
	[269] = {
		.name = "faccessat",
		.nargs = 3}
	[270] = {
		.name = "pselect6",
		.nargs = 6}
	[271] = {
		.name = "ppoll",
		.nargs = 5}
	[272] = {
		.name = "unshare",
		.nargs = 1}
	[273] = {
		.name = "set_robust_list",
		.nargs = 2}
	[274] = {
		.name = "get_robust_list",
		.nargs = 3}
	[275] = {
		.name = "splice",
		.nargs = 6}
	[276] = {
		.name = "tee",
		.nargs = 4}
	[277] = {
		.name = "sync_file_range",
		.nargs = 4}
	[278] = {
		.name = "vmsplice",
		.nargs = 4}
	[279] = {
		.name = "move_pages",
		.nargs = 6}
	[280] = {
		.name = "utimensat",
		.nargs = 4}
	[281] = {
		.name = "epoll_pwait",
		.nargs = 6}
	[282] = {
		.name = "signalfd",
		.nargs = 3}
	[283] = {
		.name = "timerfd_create",
		.nargs = 2}
	[284] = {
		.name = "eventfd",
		.nargs = 1}
	[285] = {
		.name = "fallocate",
		.nargs = 4}
	[286] = {
		.name = "timerfd_settime",
		.nargs = 4}
	[287] = {
		.name = "timerfd_gettime",
		.nargs = 2}
	[288] = {
		.name = "accept4",
		.nargs = 4}
	[289] = {
		.name = "signalfd4",
		.nargs = 4}
	[290] = {
		.name = "eventfd2",
		.nargs = 2}
	[291] = {
		.name = "epoll_create1",
		.nargs = 1}
	[292] = {
		.name = "dup3",
		.nargs = 3}
	[293] = {
		.name = "pipe2",
		.nargs = 2}
	[294] = {
		.name = "inotify_init1",
		.nargs = 1}
	[295] = {
		.name = "preadv",
		.nargs = 5}
	[296] = {
		.name = "pwritev",
		.nargs = 5}
	[297] = {
		.name = "rt_tgsigqueueinfo",
		.nargs = 4}
	[298] = {
		.name = "perf_event_open",
		.nargs = 5}
	[299] = {
		.name = "recvmmsg",
		.nargs = 5}
	[300] = {
		.name = "fanotify_init",
		.nargs = 2}
	[301] = {
		.name = "fanotify_mark",
		.nargs = 5}
	[302] = {
		.name = "prlimit64",
		.nargs = 4}
	[303] = {
		.name = "name_to_handle_at",
		.nargs = 5}
	[304] = {
		.name = "open_by_handle_at",
		.nargs = 3}
	[305] = {
		.name = "clock_adjtime",
		.nargs = 2}
	[306] = {
		.name = "syncfs",
		.nargs = 1}
	[307] = {
		.name = "sendmmsg",
		.nargs = 4}
	[308] = {
		.name = "setns",
		.nargs = 2}
	[309] = {
		.name = "getcpu",
		.nargs = 3}
	[310] = {
		.name = "process_vm_readv",
		.nargs = 6}
	[311] = {
		.name = "process_vm_writev",
		.nargs = 6}
	[312] = {
		.name = "kcmp",
		.nargs = 5}
	[313] = {
		.name = "finit_module",
		.nargs = 3}
	[314] = {
		.name = "sched_setattr",
		.nargs = 3}
	[315] = {
		.name = "sched_getattr",
		.nargs = 4}
	[316] = {
		.name = "renameat2",
		.nargs = 5}
	[317] = {
		.name = "seccomp",
		.nargs = 3}