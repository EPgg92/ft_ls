#include "ft_ls.h"

/*
** get_link:
**
** If a the given filename is a symbolic link, return the folder pointed
** by this symbolic link.
**
** return value:
** - -1 if an error occur.
** - 0 if the element isn't a symbolic link
** - 1 if the element is a symbolic link
*/

static int		get_link(char *filename, char **name_link)
{
	struct stat		info;
	char			buff[PATH_MAX];

	if (lstat(filename, &info) == -1)
		return (-1);
	if (S_ISLNK(info.st_mode))
	{
		readlink(filename, buff, PATH_MAX);
		if (!(*name_link = ft_strdup(buff)))
			return (-1);
		return (1);
	}
	return (0);
}

/*
** parse_folder:
**
** From a folder, create a t_file chained list. Follow symbolic link.
*/

int				parse_folder(char *folder, t_file **folder_list, int active_opt)
{
	struct dirent	*sub_dir;
	DIR				*dir;
	char			*linked_fold;
	int				link;

	linked_fold = NULL;
	link = 0;
	if ((link = get_link(folder, &linked_fold)) == -1)
		return (-2);
	if (!(dir = opendir(link ? linked_fold : folder)))
		return (-2);
	while ((sub_dir = readdir(dir)))
	{
		if ((active_opt & A_MIN) == 0 && sub_dir->d_name[0] == '.')
			;
		else if (push_file(folder_list, folder, sub_dir->d_name) == -1)
			return (free_folder(folder_list, -1));
	}
	if (linked_fold)
		ft_strdel(&linked_fold);
	closedir(dir);
	return (1);
}

/*
** stock_file_list:
**
** From a list of file, create a t_file chained list.
*/

int				stock_file_list(char **files, t_file **list_file)
{
	while (*files)
	{
		if (!push_file(list_file, NULL, *files))
			return (free_folder(list_file, -1));
		files++;
	}
	return (1);
}
