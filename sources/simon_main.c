#include "ft_ls.h"

void	printf_files(char **argv)
{
	ft_printf("files stocked : \n");
	while (*argv)
		ft_printf("%s\n", *argv++);
	ft_printf("\n\n");
}

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

t_file_head		*t_file_head_initialisation(void)
{
	t_file_head		*file_head;

	if (!(file_head = (t_file_head *)malloc(sizeof(t_file_head))))
		return (NULL);
	file_head->opts = 0;
	file_head->len_filename = 0;
	file_head->len_symlink = 0;
	file_head->len_user = 0;
	file_head->len_group = 0;
	file_head->len_size = 0;
	file_head->block_number = 0;
	file_head->work_list = NULL;
	file_head->arg_fold = NULL;
	file_head->file_pattern = NULL;
	return (file_head);
}


int			stock_file_list(char **files, t_file **list_file)
{
	while (*files)
	{
		if (push_file(list_file, NULL, *files))
			return (free_folder(list_file, -1));
		files++;
	}
	return (1);
}

void	set_maximum_info(t_file_head *head_file)
{
	t_file	*file_lst;
	int		tmp_len;

	file_lst = head_file->work_list;
	head_file->block_number = 0;
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

#define FOLDER	1
#define FILES	2

int			process_manager(char **file_or_dir, t_file_head *head_file, int type)
{
	int		creation;

	creation = 0;
	if (type == FOLDER)
		creation = parse_folder(*file_or_dir, &head_file->work_list);
	else if (type == FILES)
		creation = stock_file_list(file_or_dir, &head_file->work_list);
	if (creation == -1)
		return (-1);
	set_maximum_info(head_file);
	if (!get_printing_pattern(head_file))
		return (-1);
	return (1);

}

int main(int argc, char **argv)
{
	char	**files;
	t_file_head		*head_file;

	if (!(head_file = t_file_head_initialisation()))
		return (-1);
	files = NULL;
	head_file->opts = parse_argv_option(argc, argv, &files);
	if (head_file->opts == -1)
		return (ft_printf("error\n"));
	if (split_argv_filetype(files, head_file->opts, &head_file->arg_fold) == -1)
		return (ft_printf("error\n"));


	print_list(head_file->arg_fold);
	print_array(files);

}
