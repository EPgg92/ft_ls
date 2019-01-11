#include "ft_ls.h"



int	free_item(t_file **file_list, const char *path)
{
	t_file *prev;
	t_file *next;
	t_file *curr;
	int	len;

	prev = NULL;
	curr = *file_list;
	next = curr->next;
	len = ft_strlen(path);
	while (curr && ft_strncmp(curr->name, path, len + 1) != 0)
	{
		prev = curr;
		curr = next;
		if (next)
			next = next->next;
	}
	if (!curr)
		return (0);
	if (prev)
		prev->next = next;
	free_single_file(&curr);
	if (!prev && !curr)
		*file_list = next;
	return (1);
}

int	free_file(t_file **file_list, t_file **old_file)
{
	t_file *prev;
	t_file *next;
	t_file *curr;

	prev = NULL;
	curr = *file_list;
	next = curr->next;
	while (curr && *old_file != curr)
	{
		prev = curr;
		curr = next;
		if (next)
			next = next->next;
	}
	if (!curr)
		return (0);
	if (prev)
		prev->next = next;
	free_single_file(&curr);
	if (!prev && !curr)
		*file_list = next;
	*old_file = next;
	return (1);
}


void	free_hide_file(t_file **list, t_file **prev, t_file **curr, t_file **next)
{
	if (*prev)
		(*prev)->next = *next;
	free_single_file(curr);
	if (!prev && !curr)
		*list = *next;
	*curr = *next;
	if (*next)
		*next = (*next)->next;
}

void	remove_hidden(t_file **f_list, int keep_point, int keep_dbpoint)
{
	t_file *f_tmp;

	f_tmp = *f_list;
	while (f_tmp)
	{
		if (f_tmp->name[0] == '.')
		{
			if ((keep_dbpoint  == 1 && ft_strncmp("..", f_tmp->name, 3) == 0) || 
				(keep_point == 1 && ft_strncmp(".", f_tmp->name, 2) == 0))
				f_tmp = f_tmp->next;
			else
				free_file(f_list, &f_tmp);

		}
		else
		{
			if (f_tmp->fold_child)
				remove_hidden(&f_tmp->fold_child, keep_point, keep_dbpoint);
			f_tmp = f_tmp->next;
		}
	}
}
