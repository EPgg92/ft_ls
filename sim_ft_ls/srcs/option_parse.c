#include "ft_ls.h"

static t_optn *init_optn(void)
{
	t_optn *optn_list;

	optn_list = create_optn("-R", 0);
	push_front_optn(&optn_list, "-r", 0);
	push_front_optn(&optn_list, "-a", 0);
	push_front_optn(&optn_list, "-A", 0);
	push_front_optn(&optn_list, "-t", 0);
	push_front_optn(&optn_list, "-S", 0);
	push_front_optn(&optn_list, "-l", 0);
	push_front_optn(&optn_list, "-o", 0);
	push_front_optn(&optn_list, "-i", 0);
	push_front_optn(&optn_list, "-I", 0);
	return (optn_list);
}

t_optn_var	*init_optn_var(void)
{
	t_optn_var *optn_vars;

	if (!(optn_vars = (t_optn_var *)malloc(sizeof(t_optn_var))))
		return (NULL);
	optn_vars->recursive = 0;
	optn_vars->reverse = 0;
	optn_vars->all = 0;
	optn_vars->almost_all = 0;
	optn_vars->fct_sort = &alpha_cmp;
	optn_vars->long_format = 0;
	optn_vars->inode = 0;
	optn_vars->ignore = 0;
	return (optn_vars);
}

static void	set_sort_optn(t_optn *optns, t_optn_var *var_list)
{
	while (optns)
	{
		if (ft_strcmp("-t", optns->name))
			var_list->fct_sort = &modif_time_cmp;
		else if (ft_strcmp("-s", optns->name))
			var_list->fct_sort = &size_cmp;
		optns = optns->next;
	}
}


static t_optn_var	*optn_var_setup(t_optn **optns)
{
	t_optn_var	*vars;

	if (!(vars = init_optn_var()))
	{
		clear_optn_list(optns);
		return (NULL);
	}
	while (*optns)
	{
		#define SET_ARG(var_name, optn_name) \
		(!vars->var_name && !ft_strcmp((*optns)->name, optn_name))\
			vars->var_name = 1;
		if SET_ARG(recursive, "-R")
		else if SET_ARG(reverse, "-r")
		else if SET_ARG(all, "-a")
		else if SET_ARG(almost_all, "-A")
		else if SET_ARG(long_format, "-l")
		else if SET_ARG(inode, "-i")
		else if SET_ARG(ignore, "-I")
		set_sort_optn(*optns, vars);
		optns = &(*optns)->next;
	}
	return (vars);
}

int	argv_parse(int argc, char **argv, t_optn_var **optns_var)
{
	t_optn		*optns;
	int	parse_res;

	optns = init_optn();
	parse_res = optparse(argc, argv, &optns);
	if (parse_res == -1)
		return (-1);
	if (!(*optns_var = optn_var_setup(&optns)))
		return (-1);
	if (optns == NULL)
	clear_optn_list(&optns);
	return (parse_res);
}

void	print_option(t_optn_var *var_list)
{
	PRT("Recursive : %d\n", var_list->recursive);
	PRT("reverse : \n", var_list->reverse);
	PRT("All : %d\n", var_list->all);
	PRT("Almost_all : %d\n", var_list->almost_all);
	PRT("long format : %d\n", var_list->long_format);
	PRT("inode : %d\n", var_list->inode);
	PRT("ignore : %d\n", var_list->ignore);
}

