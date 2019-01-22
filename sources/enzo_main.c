#include "ft_ls.h"



int main(int argc, char **argv)
{
	char **files_names;
	t_file *folder;
	int active_opt;

	files_names = NULL;

	active_opt = parse_argv_option(argc, argv, &files_names);
	ft_printf("-a : %d\n", active_opt & A_MIN);
	parse_folder(files_names[0],&folder, active_opt);
	print_folder(folder);
	return (0);
}
