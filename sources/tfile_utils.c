#include "ft_ls.h"

char		*absolute_path(char *folder, char *file)
{
	char	*slash;
	int		allocate;

	if (ft_strequ(".", file) || ft_strequ("..", file))
		return (ft_strdup(file));
	allocate = 0;
	slash = ft_strrchr(folder, '/');
	if (slash == NULL || *(slash + 1) != '\0')
	{
		allocate = 1;
		if (!(folder = ft_strjoin(folder, "/")))
			return (NULL);
	}
	return (ft_fstrjoin(&folder, &file, allocate, 0));
}

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

int		create_tfile(char *parent, char *path, t_file **node)
{
	int		error;

	error = 1;
	if (!(*node = (t_file *)malloc(sizeof(t_file))))
		return (-1);
	(*node)->path = NULL;
	(*node)->pw_name = NULL;
	(*node)->gr_name = NULL;
	(*node)->modification_time = NULL;
	(*node)->symbolic_link = NULL;
	(*node)->next = NULL;
	(*node)->filename = NULL;
	error *= ((*node)->path = absolute_path(parent, path)) != NULL ? 1 : 0;
	error *= ((*node)->filename = ft_strdup(path)) != NULL ? 1 : 0;
	if (!((*node)->info = (struct stat*)malloc(sizeof(struct stat))))
		return (free_file_node(node, -1));
	error *= lstat((*node)->path, (*node)->info) == 0 ? 1 : 0;
	return (error == 1 ? 1: free_file_node(node, -1));
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

int		push_file(t_file **folder, char *parent_dir, char *path)
{
	if (!*folder)
		return (create_tfile(parent_dir, path, folder));
	while ((*folder)->next)
		folder = &(*folder)->next;
	return (create_tfile(parent_dir, path, &(*folder)->next));
}
