#include "ft_ls.h"

/*
** relative_path:
**
** create relative path of file relatively of folder.
**
** return value:
** NULL return if malloc fails.
** string containing relative path if success.
*/

char		*relative_path(char *folder, char *file)
{
	char	*slash;
	int		allocate;

	if (folder == NULL || ft_strequ(".", file) || ft_strequ("..", file))
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
	free((*folder)->filename);
	free((*folder)->info);
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

static void set_null_tfile(t_file **node)
{
	(*node)->info = NULL;
	(*node)->path = NULL;
	(*node)->filename = NULL;
	(*node)->pw_name = NULL;
	(*node)->gr_name = NULL;
	(*node)->modification_time = NULL;
	(*node)->next = NULL;
}

void mode_right_setup(t_file **node, char ftype, char right_0)
{
	mode_t	st_mode;
	char	*right;

	st_mode = (*node)->info->st_mode;
	right = &(*node)->right;
	(*node)->ftype = ftype;
	right[0] = right_0;
	right[1] = (st_mode & S_IRUSR) ? 'r' : '-';
	right[2] = (st_mode & S_IWUSR) ? 'w' : '-';
	right[3] = (st_mode & S_IXUSR) ? 'x' : '-';
	right[3] = (st_mode & S_ISUID && right[3] == 'x') ? 's' : 'x';
	right[3] = (st_mode & S_ISUID && right[3] == '-') ? 'S' : '-';
	right[4] = (st_mode & S_IRGRP) ? 'r' : '-';
	right[5] = (st_mode & S_IWGRP) ? 'w' : '-';
	right[6] = (st_mode & S_IXGRP) ? 'x' : '-';
	right[6] = (st_mode & S_ISGID && right[6] == 'x') ? 's' : 'x';
	right[6] = (st_mode & S_ISGID && right[6] == '-') ? 'S' : '-';
	right[7] = (st_mode & S_IROTH) ? 'r' : '-';
	right[8] = (st_mode & S_IWOTH) ? 'w' : '-';
	right[9] = (st_mode & S_IXOTH) ? 'x' : '-';
	right[9] = (st_mode & S_ISVTX && right[9] == 'x') ? 't' : 'x';
	right[9] = (st_mode & S_ISVTX && right[9] == '-') ? 'T' : '-';
	right[10] = ' '; //ACL XATRR
}

void mode(t_file **node)
{
	mode_t   st_mode;

	st_mode = (*node)->info->st_mode;
	if (st_mode & S_IXUSR && S_ISREG(st_mode))
		mode_right_setup(node, '*', '-');
	else if (S_ISREG(st_mode))
		mode_right_setup(node, ' ', '-');
	else if (S_ISDIR(st_mode))
		mode_right_setup(node, '/', 'd');
	else if (S_ISLNK(st_mode))
		mode_right_setup(node, '@', 'l');
	else if (S_ISCHR(st_mode))
		mode_right_setup(node, ' ', 'c');
	else if (S_ISBLK(st_mode))
		mode_right_setup(node, ' ', 'b');
	else if (S_ISFIFO(st_mode))
		mode_right_setup(node, '|', 'p');
	else if (S_ISSOCK(st_mode))
		mode_right_setup(node, '=', 's');
	else if (st_mode & S_IFWHT)
		mode_right_setup(node, '%', 'w');
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
	set_null_tfile(node);
	error *= ((*node)->path = relative_path(parent, path)) != NULL ? 1 : 0;
	error *= ((*node)->filename = ft_strdup(path)) != NULL ? 1 : 0;
	if (!((*node)->info = (struct stat*)malloc(sizeof(struct stat))))
		return (free_file_node(node, -1));
	error *= lstat((*node)->path, (*node)->info) == 0 ? 1 : 0;
	(*node)->pw_name = (getpwuid((*node)->info->st_uid))->pw_name;
	(*node)->gr_name = (getgrgid((*node)->info->st_gid))->gr_name;
	(*node)->modification_time = ctime(&(*node)->info->st_mtimespec.tv_sec);
	ft_bzero((*node)->symbolic_link, PATH_MAX);
	ft_bzero((*node)->right, RIGHT_LEN);
	if (S_ISLNK((*node)->info->st_mode))
		readlink((*node)->path, (*node)->symbolic_link, PATH_MAX);
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
