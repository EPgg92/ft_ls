#include "ft_ls.h"

/*
** insert_tfile_node:
**
** Small utils for place_tfile funciton, insert the new node depending
** of the presence of a previous node.
** Make chained list link between each element.
*/

static void		insert_tfile_node(t_file **sorted_folder, t_file *prev, \
		t_file *curr_tmp, t_file *new)
{
	if (!prev)
	{
		new->next = curr_tmp;
		*sorted_folder = new;

	}
	else
	{
		prev->next = new;
		new->next = curr_tmp;
	}
}

/*
** place_tfile:
**
** Place a new t_file element in the sorted chained list.
** Use different comparaison function to insert the new element.
** If someelement are equal with the comparaison function, finish
** the sort by a lexical (ascii) sort.
*/
static void		place_tfile(t_file **sorted_folder, t_file *new_file, \
							file_cmp cmp_fct)
{
	t_file	*current;
	t_file	*prev;
	int		cmp_res;

	if (!*sorted_folder)
		*sorted_folder = new_file;
	else
	{
		prev = NULL;
		current = *sorted_folder;
		while (current)
		{
			cmp_res = cmp_fct(new_file, current);
			if (cmp_res < 0 || \
				(cmp_res == 0 && ft_strcmp(new_file->path, current->path) < 0))
			{
				insert_tfile_node(sorted_folder, prev, current, new_file);
				break ;
			}
			prev = current;
			current = current->next;
			if (!current)
				prev->next = new_file;
		}
	}
}

/*
** insert_sort:
**
** Sorting a chained list of t_file according to a file_cmp function.
**
** Algorithm:
** Create a new chained list who will be entirely sorted from the beginning.
** Parse the old chained list from the first element, and insert each the 
** element at the right place according to the funciton result.
*/

void	insert_sort(t_file **folder, file_cmp cmp_function)
{
	t_file	*sorted_folder;
	t_file	*tmp;
	t_file	*next_tmp;

	sorted_folder = NULL;
	tmp = *folder;
	while (tmp)
	{
		next_tmp = tmp->next;
		tmp->next = NULL;
		place_tfile(&sorted_folder, tmp, cmp_function);
		tmp = next_tmp;
	}
	*folder = sorted_folder;
}
