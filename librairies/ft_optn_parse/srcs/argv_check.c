
#include "libopt.h"

/*
** activate_optn:
**
** Check if an argv argument arg is an option in the argument list arg_list
** If arg is in the list, set the node to arg_node
*/

int	activate_optn(char *arg, t_optn **options, t_optn **arg_node)
{
	t_optn		*optn_list;

	optn_list = *options;
	if (optn_list == NULL)
	 	return (0);
	 while (optn_list)
	 {
	 		if (optn_list->active == 1)
	 		{
				if (ft_strequ(optn_list->name, arg))
					return (deplace_option(options, optn_list));
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

void	convert_char_option(char *dest, char c)
{
	dest[0] = '-';
	dest[1] = c;
	dest[2] = '\0';
}


void		multiple_activation(t_head_optn *head, char *option_list, \
	 							t_optn **option, int index)
{
	t_optn	*option_node;
	char	tmp_opt[3];

	option_list++;
	while (*option_list)
	{
		convert_char_option(tmp_opt, *option_list);
		activate_optn(tmp_opt, option, &option_node);
		sort_optn(option, option_node);
		option_list++;
	}
	move_option(option_node, head->argv, index, &head->first_arg);
}

/*
** check_optn_arg:
**
** Check if an option need an argument, set it if needed.
**
** Return values:
** - 1 if success, if no argument is need or the argument have been caught
** - 0 if there isn't an available argument
** - -1 if malloc failed.
*/

int	check_optn_arg(t_head_optn *head, t_optn *node, int *index)
{
	if (node->expect_arg == 0)
		return (1);
	if (*index + 1 >= head->argc)
		return (0);
	if (head->argv[*index + 1][0] != '-')
	{
		node->arg = ft_strdup(head->argv[*index + 1]);
		if (!node->arg)
			return (-1);
		*index += 1;
		return (1);
	}
	return (0);
}
