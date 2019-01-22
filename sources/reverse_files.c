#include "ft_ls.h"

void reverse_files(t_file **files)
{
	t_file *current;
	t_file *next;
	t_file *prev;

	next = NULL;
	prev = NULL;
	current = *files;
	while (!current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*files = prev;
}
