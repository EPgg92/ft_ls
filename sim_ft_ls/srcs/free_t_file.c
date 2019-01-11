#include "ft_ls.h"

void	free_single_file(t_file **file)
{
	free((*file)->name);
	free((*file)->data);
	free(*file);
	*file = NULL;
}

void	free_folder(t_file **file)
{
	t_file *tmp;

	if (!*file)
		return;
	while (*file)
	{
		tmp = (*file)->next;
		free((*file)->name);
		free((*file)->data);
		free((*file)->abs_path);
		if ((*file)->fold_child)
		{
			free_folder(&(*file)->fold_child);
			free((*file)->fold_child);
		}
		free(*file);
		*file = NULL;
		file = &tmp;
	}
}
