#include "ft_ls.h"

int		free_ls_utils(t_file_head **head_file, char ***files, int status)
{
	free_file_head(head_file);
	return (free_str_array(files, status));
}

int		main(int argc, char **argv)
{
	char			**files;
	t_file_head		*head_file;
	t_file			*folders;

	if (!(head_file = NULL /*t_file_head_initialisation()*/))
		return (-1);
	files = NULL;
	if ((head_file->opts = parse_argv_option(argc, argv, &files)) == -1)
		return (free_ls_utils(&head_file, &files, -1));
	if ((argc = split_argv_filetype(files, head_file->opts, \
					&head_file->arg_fold)) == -1)
		return (free_ls_utils(&head_file, &files, -1));
	if (*files)
		if (process_manager(files, head_file, FILES) == -1)
			return (free_ls_utils(&head_file, &files, -1));
	folders = head_file->arg_fold;
	if (*files || argc > 1)
		head_file->print_foldname = 1;
	while (folders)
	{
		if (process_manager(&folders->filename, head_file, FOLDER) == -1)
			return (free_ls_utils(&head_file, &files, -1));
		folders = folders->next;
	}
	return (free_ls_utils(&head_file, &files, 0));
}
