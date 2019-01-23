#include "ft_ls.h"

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

void	print_folder(t_file *folder)
{

	while (folder)
	{
		ft_printf("%s date : %s", folder->path, \
				ctime(&folder->info->st_mtimespec.tv_sec));
		folder = folder->next;
	}
}

int		parse_folder(char *folder, t_file **folder_list, int active_opt)
{
	struct dirent	*sub_dir;
	DIR				*dir;
	char			*linked_fold;
	int				link;

	linked_fold = NULL;
	link = 0;
	if ((link = get_link(folder, &linked_fold)) == -1)
		return (-1);
	if (!(dir = opendir(link ? linked_fold : folder)))
		return (-1);
	while ((sub_dir = readdir(dir)))
	{
		if ((active_opt & A_MIN) == 0 && sub_dir->d_name[0] == '.')
			;
		else if (push_file(folder_list, folder, sub_dir->d_name) == -1)
			return (free_folder(folder_list, -1));
	}
	closedir(dir);
	return (1);
}

/*
** stock_file_list:
**
** From a list of file, create a t_file list.
*/

int			stock_file_list(char **files, t_file **list_file)
{
	while (*files)
	{
		if (!push_file(list_file, NULL, *files))
			return (free_folder(list_file, -1));
		files++;
	}
	return (1);
}
