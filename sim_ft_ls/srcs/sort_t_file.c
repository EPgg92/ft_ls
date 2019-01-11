#include "ft_ls.h"

static void	file_swap(t_file *f_prev, t_file **f_curr, t_file *f_next)
{
	if (f_prev == NULL)
	{
		(*f_curr)->next = f_next->next;
		f_next->next = *f_curr;
	}
	else
	{
		f_prev->next = f_next;
		(*f_curr)->next = f_next->next;
		f_next->next = *f_curr;
	}
	*f_curr = f_next;
}

void	sort_files(t_file **files, int (*cmp)(t_file *, t_file *))
{
	t_file *f_prev;
	t_file *last;
	t_file *tmp;

	last = NULL;
	f_prev = NULL;
	tmp = *files;
	while (last != tmp->next)
	{
		if (cmp(tmp, tmp->next) > 0)
		{
			file_swap(f_prev, &tmp, tmp->next);
			if (!f_prev)
				*files = tmp;
		}
		f_prev = tmp;
		tmp = tmp->next;
		if (tmp->next == last && last != (*files)->next)
		{
			f_prev = NULL;
			last = tmp;
			if (last->fold_child != NULL)
				sort_files(&last->fold_child, cmp);
			tmp = *files;
		}
	}
}

void	reverse_list(LIST_TYPE **list)
{
	LIST_TYPE *prev;
	LIST_TYPE *curr;
	LIST_TYPE *next;
	
	prev = NULL;
	curr = *list;
	next = (*list)->next;
	while (1)
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		if (next->next)
			next = next->next;
		else
		{
			next->next = prev;
			break ;
		}
	}
	*list = next;
}
