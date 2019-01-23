#include "ft_ls.h"

/*
** l_print:
**
** Using ft_printf for -l option.
*/

void l_print(t_file_head *head_file)
{
	t_file	*file_list;

	file_list = head_file->work_list;
	ft_printf("total %d\n", head_file->block_number);
	while (file_list)
	{
		ft_printf(head_file->print_pattern, file_list->right, file_list->info->st_nlink,
		file_list->pw_name, file_list->gr_name, file_list->info->st_size,
		file_list->modification_time, file_list->filename);
		file_list = file_list->next;
		ft_printf("\n");
	}
}

/*
** l_print:
**
** Using ft_printf for -o option.
*/

void o_print(t_file_head *head_file)
{
	t_file	*file_list;

	file_list = head_file->work_list;
	while (file_list)
	{
		ft_printf(head_file->print_pattern, file_list->right, file_list->info->st_nlink,
		file_list->pw_name, file_list->info->st_size,
		file_list->modification_time, file_list->filename);
		file_list = file_list->next;
		ft_printf("\n");
	}
}

/*
** l_print:
**
** Using ft_printf for -1 option.
*/

void	one_print(t_file_head *head_file)
{
	t_file	*file_list;

	file_list = head_file->work_list;
	while (file_list)
	{
		ft_printf(head_file->print_pattern, file_list->filename);
		file_list = file_list->next;
		ft_printf("\n");
	}
}

/*
** l_print:
**
** Using ft_printf for -m option.
*/

void 		m_print(t_file_head *head_file)
{
	t_file		*file_list;
	int 		printed;

	file_list = head_file->work_list;
	printed = 0;
	while (file_list)
	{
		if (printed + file_list->file_len + 2 > head_file->window_width)
		{
			printed = 0;
			ft_printf("\n");
		}
		else
		{
			if (!file_list->next)
				ft_printf("%s\n", file_list->filename);
			else
				printed += ft_printf("%s, ", file_list->filename);
		}
		file_list = file_list->next;
	}
}
