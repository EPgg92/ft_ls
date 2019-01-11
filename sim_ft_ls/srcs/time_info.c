#include "ft_ls.h"
#include <time.h>

char	*time_modif(t_file *file)
{
	struct timespec time;

	time = file->data->st_mtim;
	return (ctime(&time.tv_sec));
}
