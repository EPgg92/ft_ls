#include "ft_ls.h"

static void		clean_process(t_file_head *head_file)
{
	if (head_file->work_list)
		free_folder(&head_file->work_list, (int)NULL);
	ft_strdel(&head_file->print_pattern);
}

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
	select_sort(head_file->opts, &head_file->work_list);
	select_print(head_file, *file_or_dir);
	clean_process(head_file);
	return (1);

}
