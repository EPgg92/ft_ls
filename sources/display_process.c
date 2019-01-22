#include "ft_ls.h"

int			process_manager(char **file_or_dir, t_file_head *head_file, int type)
{
	int		creation;

	creation = 0;
	if (type == FOLDER)
		creation = parse_folder(*file_or_dir, \
				&head_file->work_list, head_file->opts);
	else if (type == FILES)
		creation = stock_file_list(file_or_dir, &head_file->work_list);
	if (creation == -1)
		return (-1);
	set_maximum_info(head_file);
	if (!get_printing_pattern(head_file))
		return (-1);
	ft_printf("My pattern : '%s'\n", head_file->print_pattern);
	select_sort(head_file->opts, &head_file->work_list);
	//PRINT()
	return (1);

}

