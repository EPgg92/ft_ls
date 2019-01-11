#include "ft_ls.h"

void	print_file_chained(t_file *file_list)
{
	t_stat *stat_tmp;

	while (file_list)
	{
		stat_tmp = file_list->data;
		PRT("%s %d", file_list->name, stat_tmp->st_size);
		if (file_list->next)
			PRT(" >> ");
		else
			PRT(" >> NULL\n");
		if (file_list)
			file_list = file_list->next;
	}
}
