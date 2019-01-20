#include "ft_ls.h"

int		time_compare(t_file *file_1, t_file *file_2)
{
	return (file_1->info->st_mtimespec.tv_sec - file_2->info->st_mtimespec.tv_sec);
}

int		ascii_compare(t_file *file_1, t_file *file_2)
{
	return (ft_strcmp(file_1->path, file_2->path));
}


int main(int argc, char **argv)
{
	int		activ_opt;
	t_file	*file_list;
	char	**files;

	if (((activ_opt = parse_argv_option(argc, argv, &files)) == -1))
		return (ft_printf("error\n"));
	ft_printf("value output : %d\n", activ_opt);
	if (L_MIN & activ_opt)
		ft_printf("l is active\n");
	if (U_MIN & activ_opt)
		ft_printf("u is active\n");
	if (U_MAJ & activ_opt)
		ft_printf("U is active\n");
	if (T_MIN & activ_opt)
		ft_printf("t is active\n");
	if (R_MIN & activ_opt)
		ft_printf("r is active\n");
	if (R_MAJ & activ_opt)
		ft_printf("R is active\n");
	if (O_MIN & activ_opt)
		ft_printf("o is active\n");
	if (M_MIN & activ_opt)
		ft_printf("m is active\n");
	if (S_MAJ & activ_opt)
		ft_printf("S is active\n");
	if (OPT_1 & activ_opt)
		ft_printf("1 is active\n");
	if (A_MIN & activ_opt)
		ft_printf("a is active\n");
	parse_folder(files[0], &file_list);
	print_folder(file_list);
	printf("\ninsert sort : \n");
	insert_sort(&file_list, time_compare);
	print_folder(file_list);
	printf("\nascii sort : \n");
	insert_sort(&file_list, ascii_compare);
	print_folder(file_list);
}
