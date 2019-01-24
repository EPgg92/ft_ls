#include "ft_ls.h"

void		display_total_block(int block)
{
	if (block > 0)
		ft_printf("total %d\n", block);
}

/*
** l_print:
**
** Using ft_printf for -l option.
*/

void		l_print(t_file_head *head_file)
{
	t_file	*file_list;

	file_list = head_file->work_list;
	display_total_block(head_file->block_number);
	while (file_list)
	{
		ft_printf(head_file->print_pattern, file_list->right, \
		file_list->info->st_nlink, file_list->pw_name, file_list->gr_name, \
		file_list->info->st_size, file_list->modification_time, \
		file_list->filename);
		file_list = file_list->next;
		ft_printf("\n");
	}
}

/*
** o_print:
**
** Using ft_printf for -o option.
*/

void		o_print(t_file_head *head_file)
{
	t_file	*file_list;

	file_list = head_file->work_list;
	display_total_block(head_file->block_number);
	while (file_list)
	{
		ft_printf(head_file->print_pattern, file_list->right, \
		file_list->info->st_nlink, file_list->pw_name, file_list->info->st_size,
		file_list->modification_time, file_list->filename);
		file_list = file_list->next;
		ft_printf("\n");
	}
}
