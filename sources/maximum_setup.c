#include "ft_ls.h"

/*
** reset_maximum:
**
** Set each attribute used as maximum of the t_file_head to zero.
*/

static void	reset_maximum(t_file_head *head_file)
{
	head_file->len_filename = 0;
	head_file->len_symlink= 0;
	head_file->len_user = 0;
	head_file->len_group = 0;
	head_file->len_size = 0;
	head_file->block_number = 0;
}

/*
** set_maximum_info:
**
** Parse and entire t_file list and set to the head each maximum of different
** element : - filename max len
**			 - link number max len
**			 - username max len
**			 - groupname max len
**			 - file size max len
** Count also the total number of blocks.
*/
void	set_maximum_info(t_file_head *head_file)
{
	t_file	*file_lst;
	int		tmp_len;

	reset_maximum(head_file);
	file_lst = head_file->work_list;
	while (file_lst)
	{
		tmp_len = ft_strlen(file_lst->filename);
		if (tmp_len > head_file->len_filename)
			head_file->len_filename = tmp_len;
		tmp_len = ft_unbrlen(file_lst->info->st_nlink);
		if (tmp_len > head_file->len_symlink)
			head_file->len_symlink = tmp_len;
		tmp_len = ft_strlen(file_lst->pw_name);
		if (tmp_len > head_file->len_symlink)
			head_file->len_user = tmp_len;
		tmp_len = ft_strlen(file_lst->gr_name);
		if (tmp_len > head_file->len_group)
			head_file->len_group = tmp_len;
		tmp_len = ft_unbrlen(file_lst->info->st_size);
		if (tmp_len > head_file->len_size)
			head_file->len_size = tmp_len;
		head_file->block_number += file_lst->info->st_blocks;
		file_lst = file_lst->next;
	}
}
