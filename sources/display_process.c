#include "ft_ls.h"

/*
** clean_process:
**
** Freeing function to liberate element used only during the process.
*/

static void	clean_process(t_file_head *head_file)
{
	if (head_file->work_list)
		free_folder(&head_file->work_list, (int)NULL);
	ft_strdel(&head_file->print_pattern);
}

/*
** recursive_folders:
**
** Parse the current t_file_head->work_list, and call the process_manager
** function for each directory.
*/

static void	recursive_folders(t_file_head *head_file)
{
	t_file	*folder_list;
	t_file	*save_folder;

	folder_list = head_file->work_list;
	save_folder = head_file->work_list;
	head_file->work_list = NULL;
	ft_strdel(&head_file->print_pattern);
	head_file->print_foldname = 1;
	while (folder_list)
	{
		if (!ft_strequ("..", folder_list->filename) && \
			!ft_strequ(".", folder_list->filename) &&
			S_ISDIR(folder_list->info->st_mode))
			process_manager(&folder_list->path, head_file, FOLDER);
		folder_list = folder_list->next;
	}
	head_file->work_list = save_folder;
}

/*
** show_error:
**
** Function called to display an error message with errno when a folder can't
** be read.
*/

int			show_error(t_file_head *head_file, char *directory, int status)
{
	if (head_file->file_printed >= 1)
		ft_printf("\n");
	if (head_file->print_foldname)
		ft_printf("%s:\n", directory);
	ft_putstr_fd("ft_ls: ", STDERR_FILENO);
	perror(directory);
	head_file->file_printed++;
	return (status);
}


/*
** process_manager:
**
** Function to perform the parsing, the sorting and the printing of a chained
** list, from a folder name or a list of files.
**
** Process steps:
** 	1) Create a t_file list
**  2) Set informations on maximums of the list.
**	3) Format a printing pattern
**	4) Sort the list
**	5) display it
**	+ optionnal) Call the function recursively for each folder if needed.
*/

int			process_manager(char **file_or_dir, t_file_head *head_file, \
																	int type)
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
	else if (creation == -2)
		return (show_error(head_file, *file_or_dir, 0));
	set_maximum_info(head_file);
	if (!get_printing_pattern(head_file))
		return (-1);
	select_sort(head_file->opts, &head_file->work_list);
	select_print(head_file, *file_or_dir);
	if (head_file->opts & R_MAJ)
		recursive_folders(head_file);
	clean_process(head_file);
	return (1);
}
