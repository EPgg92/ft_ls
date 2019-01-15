
#include "libopt.h"

/*
** ft_optn_in:
**
** Check if an argv argument arg is an option in the argument list arg_list
** If arg is in the list, set the node to arg_node
*/

int	ft_optn_in(t_optn *optn_list, char *arg, t_optn **arg_node)
{
	if (optn_list == NULL)
		return (0);
	while (optn_list)
	{
		if (optn_list->active == 1)
		{
			optn_list = optn_list->next;
			continue ;
		}
		if (ft_strcmp(arg, optn_list->name) == 0)
		{
			optn_list->active = 1;
			*arg_node = optn_list;
			return (1);
		}
		optn_list = optn_list->next;
	}
	return (0);
}

/*
** check_optn_arg:
**
** Check if an option need an argument, set it if needed.
**
** Return values:
** - 0 if an error occur
** - 1 if success, if no argument is need or the argument have been caught
*/

int	check_optn_arg(t_optn *node, int argc, char **argv, int *index, t_head_optn *head)
{
	if (node->expect_arg == 0)
		return (1);
	if (*index + 1 >= argc)
		return (0);
	if (ft_is_optn(argv[*index + 1], head) == 0 &&\
			ft_strncmp("--", argv[*index + 1], 3) != 0)
	{
		node->arg = argv[*index + 1];
		*index += 1;
		return (1);
	}
	return (0);
}
