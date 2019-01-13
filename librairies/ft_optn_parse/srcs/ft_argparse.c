

#include "libopt.h"

/*
** move_option:
**
** Move in argv an option argument before all real program arguments
** Switch an option and his argument if necessary.
*/

void	move_option(t_optn *optn_node, char **argv, int index, int *first_arg)
{
	if (*first_arg == 0)
		return ;
	while (index > *first_arg)
	{
		if (optn_node->expect_arg == 1)
		{
			ft_strswap(argv + index, argv + index - 1);
			ft_strswap(argv + index, argv + index + 1);
		}
		else
			ft_strswap(argv + index, argv + index - 1);
		index--;
	}
	*first_arg += optn_node->expect_arg ? 2 : 1;
}

/*
** sort_optn:
**
** Sort a t_optn list, pushing all active argument at the top of the list.
** Called each time a new option is found to keep the option apparition order.
**
** Return value :
** - 0 if optn is placed.
** - 1 if all option have been caught.
*/

int		sort_optn(t_optn **begin_list, t_optn *optn)
{
	t_optn *tmp_prev;
	t_optn *tmp_curr;

	if (!ft_strcmp((*begin_list)->name, optn->name))
		return (0);
	tmp_prev = *begin_list;
	while (ft_strcmp(optn->name, tmp_prev->next->name) != 0)
		tmp_prev = tmp_prev->next;
	if (tmp_prev->active && optn->next == NULL)
		return (1);
	tmp_prev->next = optn->next;
	tmp_prev = NULL;
	tmp_curr = *begin_list;
	while (tmp_curr && tmp_curr->active == 1)
	{
		tmp_prev = tmp_curr;
		tmp_curr = tmp_curr->next;
	}
	if (tmp_prev)
		tmp_prev->next = optn;
	optn->next = tmp_curr;
	if (!tmp_prev)
		*begin_list = optn;
	return (0);
}

/*
** optparse:
**
** Main function to perform our option parsing from argc & argv.
** Arguments :
** - argc & argv : directly from a main function
** - optn_required : a chained list of t_optn, create before function call.
**
** Return :
** 	1)-1 if an error occur
**	2) 0 if argv contains no arguments, only options.
**	3) n whitch is the index of the first non-option element of argv.
**
** optn_required :
** 	To create this list, you need to use list functions to add your
**	personnal options.
**
**	Modification of the list during function call :
**	1) active is set to 1 if option is available.
**	2) list is sorted by apparition order.
**	3) Unused option are removed
**
** Modification on argv:
** 	1) All argument who aren't option will be pushed at the end of argv.
*/

int		optparse(int argc, char **argv, t_optn **optn_required)
{
	int		index;
	t_optn	*arg_node;
	int		arg_res;
	int		first_arg;
	int		hyphen;
	int		is_optn_res;

	if (argc == 1 || *optn_required == NULL)
		return (-1);
	index = 1;
	first_arg = 0;
	while (index < argc && (hyphen = ft_strncmp("--", argv[index], 3)) != 0)
	{
		is_optn_res = ft_is_optn(argv[index]);
		if (is_optn_res && ft_optn_in(*optn_required, \
					argv[index], &arg_node))
		{
			arg_res = check_optn_arg(arg_node, argc, argv, &index);
			if (arg_res == 0)
			{
				printf("Option error : %s argument is missing\n", \
						arg_node->name);
				clear_optn_list(optn_required);
				return (-1);
			}
			move_option(arg_node, argv, \
					arg_node->expect_arg == 1 ? index - 1 : index, &first_arg);
			sort_optn(optn_required, arg_node);
		}
		else if (is_optn_res == 1)
			ft_move_strtab(argv, argc, index, first_arg ? first_arg++ : 0);
		else if (is_optn_res == 0 && first_arg == 0)
			first_arg = index;
		index++;
	}
	if (hyphen == 0)
		ft_move_strtab(argv, argc, index, first_arg);
	remove_unactive(optn_required);
	return (first_arg);
}
