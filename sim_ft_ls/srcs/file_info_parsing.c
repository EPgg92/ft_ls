#include "ft_ls.h"

void	print_links(t_file *file)
{
	PRT("%d", file->data->st_nlink);
}
