#include "ft_ls.h"

/*
** free_file_node:
**
** Free each element of a single t_file element.
*/

int				free_file_node(t_file **folder, int status)
{
	ft_strdel(&(*folder)->path);
	ft_strdel(&(*folder)->filename);
	free((*folder)->info);
	(*folder)->info = NULL;
	ft_strdel(&(*folder)->pw_name);
	ft_strdel(&(*folder)->gr_name);
	ft_strdel(&(*folder)->modification_time);
	free(*folder);
	*folder = NULL;
	return (status);
}

/*
** free_folder:
**
** Free an entire chained list of t_file.
*/

int				free_folder(t_file **folder, int status)
{
	if (!*folder)
		return (status);
	if ((*folder)->next)
		free_folder(&(*folder)->next, status);
	return (free_file_node(folder, status));
}

/*
** set_null_tfile:
**
** Set each attribute of a t_file to NULL or 0.
*/

static void		set_null_tfile(t_file *node)
{
	node->info = NULL;
	node->path = NULL;
	node->filename = NULL;
	node->pw_name = NULL;
	node->gr_name = NULL;
	node->modification_time = NULL;
	node->next = NULL;
	node->file_len = 0;
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

int				create_tfile(char *parent, char *path, t_file **node)
{
	int		error;

	error = 1;
	if (!(*node = (t_file *)malloc(sizeof(t_file))))
		return (-1);
	set_null_tfile(*node);
	error *= ((*node)->path = join_path(parent, path)) != NULL ? 1 : 0;
	error *= ((*node)->filename = ft_strdup(path)) != NULL ? 1 : 0;
	if (!((*node)->info = (struct stat*)malloc(sizeof(struct stat))))
		return (free_file_node(node, -1));
	error *= lstat((*node)->path, (*node)->info) == 0 ? 1 : 0;
	(*node)->pw_name = ft_strdup(getpwuid((*node)->info->st_uid)->pw_name);
	(*node)->gr_name = ft_strdup(getgrgid((*node)->info->st_gid)->gr_name);
	if (!(*node)->pw_name || !(*node)->pw_name)
		error = 0;
	(*node)->modification_time = NULL;
	ft_bzero((*node)->symbolic_link, PATH_MAX);
	ft_bzero((*node)->right, RIGHT_LEN);
	ft_memset((*node)->right, (int)'-', RIGHT_LEN - 2);
	parse_mode(*node);
	return (error == 1 ? 1 : free_file_node(node, -1));
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

int				push_file(t_file **folder, char *parent_dir, char *path)
{
	if (!*folder)
		return (create_tfile(parent_dir, path, folder));
	while ((*folder)->next)
		folder = &(*folder)->next;
	return (create_tfile(parent_dir, path, &(*folder)->next));
}
