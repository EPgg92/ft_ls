#include "ft_ls.h"

/*
** reset_maximum:
**
** Set each attribute used as maximum of the t_file_head to zero.
*/

static void		reset_maximum(t_file_head *head_file)
{
	head_file->len_filename = 0;
	head_file->len_symlink = 0;
	head_file->len_user = 0;
	head_file->len_group = 0;
	head_file->len_size = 0;
	head_file->block_number = 0;
	head_file->files_number = 0;
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

#define UPDATE_LEN(ref, new) ref = new > ref ? new : ref

void			set_maximum_info(t_file_head *head_file)
{
	t_file	*file_lst;
	int		tmp_len;

	reset_maximum(head_file);
	file_lst = head_file->work_list;
	while (file_lst)
	{
		head_file->files_number++;
		file_lst->file_len = ft_strlen(file_lst->filename);
		UPDATE_LEN(head_file->len_filename, file_lst->file_len);
		tmp_len = ft_unbrlen(file_lst->info->st_nlink);
		UPDATE_LEN(head_file->len_symlink, tmp_len);
		tmp_len = ft_strlen(file_lst->pw_name);
		UPDATE_LEN(head_file->len_user, tmp_len);
		tmp_len = ft_strlen(file_lst->gr_name);
		UPDATE_LEN(head_file->len_group, tmp_len);
		tmp_len = ft_unbrlen(file_lst->info->st_size);
		UPDATE_LEN(head_file->len_size, tmp_len);
		head_file->block_number += file_lst->info->st_blocks;
		set_file_link(file_lst, head_file->opts);
		file_lst = file_lst->next;
	}
}
