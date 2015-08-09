#include <sys/ptrace.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "ft_strace.h"

char *read_string_tab(int child, long addr)
{
	int too_long = 0;
	char *val = malloc(50);
	*val = 0;
	char *elem;
    unsigned int allocated = 50;
    unsigned int read = 0;
    unsigned int size = 0;
    long data;
    int i = 0;
    while (1)
    {
    	data = ptrace(PTRACE_PEEKDATA, child, addr + read);
        if(errno != 0)
        {
            val[read] = 0;
            break;
        }
        if (!data)
        	break;
        elem = read_string(child, data);
        int tmp_size = strlen(elem);
        if (size + 2 + (!i ? 2 : 0) + tmp_size >= allocated)
	    	too_long = 1;
	    if (!too_long)
	    {
        	int p = sprintf(val + size, "%s\"%s\"", !i ? "" : ", ", elem);
        	size += p;
	    }
	    free(elem);
    	i++;
        read += sizeof data;
    }
    if (too_long)
    	sprintf(val, "/* %d vars */", i);
    return val;
}