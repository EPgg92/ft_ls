#include "ft_ls.h"

/*
** free_head:
**
** Free each element of a t_file_head.
*/

void			free_file_head(t_file_head **head_file)
{
	free((*head_file)->print_pattern);
	free_folder(&(*head_file)->arg_fold, 0);
	free(*head_file);
	*head_file = NULL;
}

/*
** t_file_head_initialisation:
**
** Allocate a t_file_head element and set each attributes to 0 (or NULL).
**
** return value:
** The t_file_head newly allocated or NULL if an error occur.
*/

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
	file_head->print_pattern = NULL;
	file_head->print_foldname = 0;
	file_head->file_printed = 0;
	return (file_head);
}
