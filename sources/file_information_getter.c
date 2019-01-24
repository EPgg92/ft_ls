#include "ft_ls.h"

/*
** set_file_link:
**
** If the t_file element is a symbolic link, get the file pointed by the link.
** If -l or -o are activate, format the t_file->filename element for printing
*/

int				set_file_link(t_file *file_node, int options)
{
	char	*formated_link;
	char	*tmp_str;

	if (S_ISLNK(file_node->info->st_mode) == 0)
		return (1);
	readlink(file_node->path, file_node->symbolic_link, PATH_MAX);
	if (options & L_MIN || options & O_MIN)
	{
		tmp_str = " -> ";
		formated_link = ft_fstrjoin(&file_node->filename, &tmp_str, 1, 0);
		if (!formated_link)
			return (-1);
		tmp_str = file_node->symbolic_link;
		formated_link = ft_fstrjoin(&formated_link, &tmp_str, 1, 0);
		file_node->filename = formated_link;
	}
	return (file_node->filename ? 1 : -1);
}

/*
** right_setup:
**
** Analyse for a t_file the value for each right type (User, group, other)
** to see what is active. Store this information in the t_file->right element.
*/

static void		right_setup(t_file **node, char ftype, char right_0)
{
	mode_t	st_mode;

	st_mode = (*node)->info->st_mode;
	(*node)->ftype = ftype;
	(*node)->right[0] = right_0;
	(*node)->right[1] = (st_mode & S_IRUSR) ? 'r' : '-';
	(*node)->right[2] = (st_mode & S_IWUSR) ? 'w' : '-';
	(*node)->right[3] = (st_mode & S_IXUSR) ? 'x' : '-';
	if ((*node)->right[3] == 'x')
		(*node)->right[3] = st_mode & S_ISUID ? 's' : 'x';
	else
		(*node)->right[3] = (st_mode & S_ISUID && (*node)->right[3] == '-') ? 'S' : '-';
	(*node)->right[4] = (st_mode & S_IRGRP) ? 'r' : '-';
	(*node)->right[5] = (st_mode & S_IWGRP) ? 'w' : '-';
	(*node)->right[6] = (st_mode & S_IXGRP) ? 'x' : '-';
	if ((*node)->right[6] == 'x')
		(*node)->right[6] = st_mode & S_ISGID ? 's' : 'x';
	else
		(*node)->right[6] = st_mode & S_ISGID ? 'S' : '-';
	(*node)->right[7] = (st_mode & S_IROTH) ? 'r' : '-';
	(*node)->right[8] = (st_mode & S_IWOTH) ? 'w' : '-';
	(*node)->right[9] = (st_mode & S_IXOTH) ? 'x' : '-';
	if ((*node)->right[9] == 'x')
		(*node)->right[9] = st_mode & S_ISVTX ? 't' : 'x';
	else
		(*node)->right[9] = st_mode & S_ISVTX ? 'T' : '-';
}

/*
** parse_mode:
**
** Used to store information related to the rights and the file type.
*/

void			parse_mode(t_file **node)
{
	mode_t   st_mode;

	st_mode = (*node)->info->st_mode;
	if (st_mode & S_IXUSR && S_ISREG(st_mode))
		right_setup(node, '*', '-');
	else if (S_ISREG(st_mode))
		right_setup(node, ' ', '-');
	else if (S_ISDIR(st_mode))
		right_setup(node, '/', 'd');
	else if (S_ISLNK(st_mode))
		right_setup(node, '@', 'l');
	else if (S_ISCHR(st_mode))
		right_setup(node, ' ', 'c');
	else if (S_ISBLK(st_mode))
		right_setup(node, ' ', 'b');
	else if (S_ISFIFO(st_mode))
		right_setup(node, '|', 'p');
	else if (S_ISSOCK(st_mode))
		right_setup(node, '=', 's');
	else if (st_mode & S_IFWHT)
		right_setup(node, '%', 'w');
}
