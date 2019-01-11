#include <dirent.h>
#include "ft_ls.h"

t_file	*dir_parser(const char *dir, int recursiv)
{
	DIR *fd_dir;
	struct dirent *file_buf;
	t_file	*file_list;
	t_stat	*f_info;
	t_file	*child_file;

	file_list = NULL;
	if (!(fd_dir = opendir(dir)))
		return (NULL);
	while ((file_buf = readdir(fd_dir)))
	{
		f_info = (t_stat *)malloc(sizeof(t_stat));
		child_file = push_back_file(&file_list, file_buf->d_name, f_info, dir);
		if (stat(child_file->abs_path, f_info) == - 1)
			return (NULL);
		if (recursiv && S_ISDIR(f_info->st_mode))
			if (ft_strncmp(child_file->name, ".", 2) != 0 &&
				ft_strncmp(child_file->name, "..", 3) != 0)
				child_file->fold_child = dir_parser(child_file->abs_path, recursiv);
	}
	return (file_list);
}
