#include "ft_strace.h"

long	get_arg(t_regs regs, int num)
{
	switch (num)
	{
		case 0: return regs.rdi;
    	case 1: return regs.rsi;
   		case 2: return regs.rdx;
    	case 3: return regs.r10;
    	case 4: return regs.r8;
    	case 5: return regs.r9;
	}
	return 0;
}