#include "ft_ls.h"

void	print_array(char **array)
{
	ft_printf("New printf : \n");
	while (*array)
		ft_printf("%s\n", *array++);
	ft_printf("\n\n");
}

void	print_list(t_file *file_list)
{
	ft_printf("New printf list :\n");
	while (file_list)
	{
		ft_printf("%s\n", file_list->path);
		file_list = file_list->next;
	}
	ft_printf("\n\n");
}


void		print_max(t_file_head *head)
{
	ft_printf("file : %d | symlink : %d | user %d | group : %d | size : %d\nblocks: %d\n",
			head->len_filename, head->len_symlink, head->len_user, head->len_group,
			head->len_size, head->block_number);
}

int main(int argc, char **argv)
{
	char	**files;
	t_file_head		*head_file;
	t_file			*folders;

	if (!(head_file = t_file_head_initialisation()))
		return (-1);
	files = NULL;
	head_file->opts = parse_argv_option(argc, argv, &files);
	if (head_file->opts == -1)
		return (ft_printf("error\n"));
	if ((argc = split_argv_filetype(files, head_file->opts, \
					&head_file->arg_fold)) == -1)
		return (ft_printf("error\n"));
	if (*files)
	{
		process_manager(files, head_file, FILES);
		head_file->print_foldname = 1;
	}
	folders = head_file->arg_fold;
	if (t_file_list_len(head_file->arg_fold) >= 2)
		head_file->print_foldname = 1;
	while (folders)
	{
		process_manager(&folders->filename, head_file, FOLDER);
		folders = folders->next;
	}
}
