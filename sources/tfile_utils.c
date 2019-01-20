#include "ft_ls.h"

/*
** free_file_node:
**
** Free each element of a single t_file element.
*/

int		free_file_node(t_file **folder, int status)
{
	free((*folder)->path);
	free((*folder)->pw_name);
	free((*folder)->modification_time);
	free((*folder)->symbolic_link);
	free(*folder);
	*folder = NULL;
	return (status);
}

/*
** free_folder:
**
** Free an entire chained list of t_file.
*/

int		free_folder(t_file **folder, int status)
{
	if ((*folder)->next)
		free_folder(&(*folder)->next, status);
	return (free_file_node(folder, status));
}

/*
** create_file:
**
** Allocate a new t_file element, set almost all attribute to NULL,
** and malloc also the struct stat *info element.
** 
** return value:
** - -1 if an allocation error occur.
** - 1 if the allocation succeed.
*/

int		create_tfile(char *path, t_file **node)
{
	if (!(*node = (t_file *)malloc(sizeof(t_file))))
		return (-1);
	(*node)->path = NULL;
	(*node)->pw_name = NULL;
	(*node)->gr_name = NULL;
	(*node)->modification_time = NULL;
	(*node)->symbolic_link = NULL;
	(*node)->next = NULL;
	if (!((*node)->info = (struct stat*)malloc(sizeof(struct stat))))
		return (free_file_node(node, -1));
	if (lstat(path, (*node)->info) == -1)
		return (free_file_node(node, -1));
	if (!((*node)->path = ft_strdup(path)))
		return (free_file_node(node, -1));
	return (1);
}

/*
** push_file:
**
** Push a single t_file struct at the end of the chained list.
**
** return value:
** - -1 if an allocation error occur.
** - 1 if the allocation succeed.
*/

int		push_file(t_file **folder, char *path)
{
	if (!*folder)
		return (create_tfile(path, folder));
	while ((*folder)->next)
		folder = &(*folder)->next;
	return (create_tfile(path, &(*folder)->next));
}
