
#ifndef OPTN_VARS_H
#define OPTN_VARS_H
 
#include "ft_ls.h"

typedef struct	s_optn_var
{
	int recursive;
	int reverse;
	int all;
	int almost_all;
	t_fct_cmp fct_sort;
	int long_format;
	int inode;
	int ignore;
}		t_optn_var;

#endif
