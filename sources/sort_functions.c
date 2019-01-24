#include "ft_ls.h"

/*
** modif_compare:
**
** compare modification date of file_1 and file_2 with a difference
**
** return value
** difference between modification date of file_1
** and modification date of file_2
*/

int		modif_compare(t_file *file_1, t_file *file_2)
{
	return (file_2->info->st_mtimespec.tv_sec - \
			file_1->info->st_mtimespec.tv_sec);
}

/*
** access_compare:
**
** compare last acess date of file_1 and file_2 with a difference
**
** return value
** difference between last acess date of file_1 and last acess date of file_2
*/

int		access_compare(t_file *file_1, t_file *file_2)
{
	return (file_1->info->st_atimespec.tv_sec - \
			file_2->info->st_atimespec.tv_sec);
}

/*
** creation_compare:
**
** compare creation date of file_1 and file_2 with a difference
**
** return value
** difference between creation date of file_1 and creation date of file_2
*/

int		creation_compare(t_file *file_1, t_file *file_2)
{
	return (file_1->info->st_birthtimespec.tv_sec - \
			file_2->info->st_birthtimespec.tv_sec);
}

/*
** ascii_compare:
**
** compare name of file_1 and file_2 with a ft_strcmp
**
** return value
** difference between two different char of name of file_1 and name of file_2
*/

int		ascii_compare(t_file *file_1, t_file *file_2)
{
	return (ft_strcmp(file_1->filename, file_2->filename));
}

/*
** size_compare:
**
** compare size of file_1 and file_2 with a difference
**
** return value
** difference between size of file_1 and size of file_2
*/


int		size_compare(t_file *file_1, t_file *file_2)
{
	return (file_2->info->st_size - file_1->info->st_size);
}
