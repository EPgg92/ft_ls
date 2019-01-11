#include "ft_ls.h"

char	*ft_pathjoin(const char *dir, const char *filename)
{
	char *abs_path;
	int index;

	abs_path = (char *)malloc(sizeof(char) * (ft_strlen(dir) + ft_strlen(filename) + 2));
	while (*dir)
		abs_path[index++] = *dir++;
	abs_path[index++] = '/';
	while (*filename)
		abs_path[index++] = *filename++;
	abs_path[index] = '\0';
	return (abs_path);
}

t_file	*create_file_elem(const char *name, struct stat *file_stat, const char *dir)
{
	t_file	*file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	file->name = ft_strdup(name);
	file->data = file_stat;
	file->next = NULL;
	file->abs_path = ft_pathjoin(dir, name);
	file->fold_child = NULL;
	return (file);
}

void	push_front_file(t_file **file_list, const char *name, t_stat *f_info, const char *dir)
{
	t_file *tmp;

	if (!*file_list)
		*file_list = create_file_elem(name, f_info, dir);
	else
	{
		tmp = create_file_elem(name, f_info, dir);
		tmp->next = *file_list;
		*file_list = tmp;
	}
}

t_file	*push_back_file(t_file **file_list, const char *name, t_stat *f_info, const char *dir)
{
	if (!*file_list)
	{
		*file_list = create_file_elem(name, f_info, dir);
		return (*file_list);
	}
	else
	{
		while ((*file_list)->next)
			file_list = &(*file_list)->next;
		(*file_list)->next = create_file_elem(name, f_info, dir);
		return ((*file_list)->next);
	}
}
