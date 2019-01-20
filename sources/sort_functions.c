#include "ft_ls.h"

int		modif_compare(t_file *file_1, t_file *file_2)
{
	return (file_1->info->st_mtimespec.tv_sec - \
			file_2->info->st_mtimespec.tv_sec);
}

int		access_compare(t_file *file_1, t_file *file_2)
{
	return (file_1->info->st_atimespec.tv_sec - \
			file_2->info->st_atimespec.tv_sec);
}

int		creation_compare(t_file *file_1, t_file *file_2)
{
	return (file_1->info->st_birthtimespec.tv_sec - \
			file_2->info->st_birthtimespec.tv_sec);
}

int		ascii_compare(t_file *file_1, t_file *file_2)
{
	return (ft_strcmp(file_1->filename, file_2->filename));
}

int		size_compare(t_file *file_1, t_file *file_2)
{
	return (file_2->info->st_size - file_1->info->st_size);
}
