#include "ft_ls.h"
#include <dirent.h>
#include <time.h>

static void		insert_tfile_node(t_file **sorted_folder, t_file *prev, \
		t_file *curr_tmp, t_file *new)
{
	if (!prev)
	{
		new->next = curr_tmp;
		*sorted_folder = new;

	}
	else
	{
		prev->next = new;
		new->next = curr_tmp;
	}
}

static void		place_tfile(t_file **sorted_folder, t_file *new_file, \
							file_cmp cmp_fct)
{
	t_file	*current;
	t_file	*prev;
	int		cmp_res;

	if (!*sorted_folder)
		*sorted_folder = new_file;
	else
	{
		prev = NULL;
		current = *sorted_folder;
		while (current)
		{
			cmp_res = cmp_fct(new_file, current);
			if (cmp_res < 0 || \
				(cmp_res == 0 && ft_strcmp(new_file->path, current->path) < 0))
			{
				insert_tfile_node(sorted_folder, prev, current, new_file);
				break ;
			}
			prev = current;
			current = current->next;
			if (!current)
				prev->next = new_file;
		}
	}
}

void	insert_sort(t_file **folder, file_cmp cmp_function)
{
	t_file	*sorted_folder;
	t_file	*tmp;
	t_file	*next_tmp;

	sorted_folder = NULL;
	tmp = *folder;
	while (tmp)
	{
		next_tmp = tmp->next;
		tmp->next = NULL;
		place_tfile(&sorted_folder, tmp, cmp_function);
		tmp = next_tmp;
	}
	*folder = sorted_folder;
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
