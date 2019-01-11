#include "libopt.h"
#include "ft_ls.h"


void	default_display(t_optn_var *ls_optns)
{
	t_file *cwd;

	cwd = dir_parser(".", 0);
	remove_hidden(&cwd, 0, 0);
	sort_files(&cwd, &alpha_cmp);
	folder_print(".", cwd, ls_optns);
	//free_folder(&cwd);
}

int ft_add(int a, int b)
{
	return (a + b);
}

void	multiple_directory(int argc, char **argv, int arg_start, t_optn_var *optns)
{
	t_file *directory;
	int multiple_fold;
	
	multiple_fold = argc - arg_start >= 2 ? 1 : 0;
	while (arg_start < argc)
	{
		directory = dir_parser(argv[arg_start], optns->recursive);
		remove_hidden(&directory, optns->almost_all, optns->almost_all);
		sort_files(&directory, optns->fct_sort);
		if (optns->reverse)
			reverse_list(&directory);
		if (optns->recursive)
			folder_print(argv[arg_start], directory, optns);
		else
		{
			if (multiple_fold)
				PRT("%s/:\n", argv[arg_start]);
			folder_print(argv[arg_start], directory, optns);
			if (argc - 1 != arg_start)
				PRT("\n");
		}
		free_folder(&directory);
		arg_start++;
	}
}

void	current_directory(t_optn_var *optns)
{
	t_file *cwd;

	cwd = dir_parser(".", optns->recursive);
	remove_hidden(&cwd, optns->almost_all, optns->almost_all);
	sort_files(&cwd, optns->fct_sort);
	if (optns->reverse)
		reverse_list(&cwd);
	free_folder(&cwd);
}

int	main(int argc, char **argv)
{
	t_optn_var *optns;
	int	args_start;

	optns = init_optn_var();
	if (argc == 1)
		default_display(optns);
	else
	{
		args_start = argv_parse(argc, argv, &optns);
		if (args_start  == 0)
			current_directory(optns);
		else if (args_start >= 1)
			multiple_directory(argc, argv, args_start, optns);
		else
			PRT("%s : Error options.\n", argv[0]);
	}
}
