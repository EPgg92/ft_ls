

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
** manage_option:
**
**
** return value:
**
**		- 0 is a program argument
**		- -1 invalid option
**		- -2 malloc error
*/

int		manage_option(t_head_optn *head, int *index)
{
	int		valid_opt;
	int		valid_arg;
	t_optn	*working_node;

	if ((valid_opt = analyse_optn(head->argv[*index], head)) <= 0)
	{
		if (valid_opt == 0 && head->first_arg == 0)
			head->first_arg = *index;
		return (valid_opt);
	}
	else if (valid_opt == 4)
		multiple_activation(head, head->argv[*index] , &working_node, *index);
	else
	{
		activate_optn(head->argv[*index], &head->next, &working_node);
		valid_arg = check_optn_arg(head, working_node, index);
		if (valid_arg <= 0)
			return (valid_arg == -1 ? -2 : -3);
		sort_optn(&head->next, working_node);
		move_option(working_node, head->argv, \
			(working_node->expect_arg == 1 ? *index - 1 : *index), &head->first_arg);
	}
	return (valid_opt);
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

int		duplicate_arguments(int argc, char **argv, t_head_optn *head)
{
	head->argc = argc;
	head->argv = ft_duparray(argv);
	return (head->argv != NULL);
}


int		optparse(int argc, char **argv, t_head_optn *head)
{
	int		index;
	t_optn 	**optn_required;
	int		hyphen;

	if (!(duplicate_arguments(argc, argv, head)))
		return (-1);
	optn_required = &head->next;
	if (head->argc == 1 || *optn_required == NULL)
		return (-1);
	index = 1;
	head->first_arg = 0;
	while (index < head->argc && \
		(hyphen = ft_strncmp("--",head->argv[index], 3)) != 0)
	{
		manage_option(head, &index); // get value
		index++;
	}
	if (hyphen == 0)
		ft_move_strtab(head->argv, head->argc, index, head->first_arg);
	remove_unactive(optn_required);
	return (head->first_arg);
}
