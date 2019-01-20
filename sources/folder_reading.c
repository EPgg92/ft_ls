#include "ft_ls.h"
#include <dirent.h>
#include <time.h>

void	print_folder(t_file *folder)
{

	while (folder)
	{
		ft_printf("%s date : %s", folder->path, \
				ctime(&folder->info->st_mtimespec.tv_sec));
		folder = folder->next;
	}
}

int		parse_folder(char *folder, t_file **folder_list)
{
	struct dirent	*sub_dir;
	DIR				*dir;

	if (!(dir = opendir(folder)))
		return (-1);
	while ((sub_dir = readdir(dir)))
	{
		if (push_file(folder_list, folder, sub_dir->d_name) == -1)
			return (free_folder(folder_list, -1));
	}
	closedir(dir);
	return (1);
}



int			test_readdir(char *name_dir)
{
    DIR *d;
    struct dirent *dir;
	struct stat info;

    d = opendir(name_dir);
	ft_printf("d value %p\n", d);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
            printf("%s\n", dir->d_name);
        closedir(d);
    }
	if (lstat(name_dir, &info) == -1)
		return (ft_printf("error\n"));
	ft_printf("mode : %o\n", info.st_mode);
    return(0);
}
