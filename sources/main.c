#include "ft_ls.h"


int main(int argc, char **argv)
{
	char		**file_list;
	int			activ_opt;
	t_file		*folder_list;

	if ((activ_opt = parse_argv_option(argc, argv, &file_list)) == -1)
		return (-1);
	if (split_argv_filetype(file_list, activ_opt, &folder_list) == -1)
		return (-1);
	return (0);
}
