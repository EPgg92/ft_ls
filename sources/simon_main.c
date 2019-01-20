#include "ft_ls.h"

void	printf_files(char **argv)
{
	ft_printf("files stocked : \n");
	while (*argv)
		ft_printf("%s\n", *argv++);
	ft_printf("\n\n");
}


int main(int argc, char **argv)
{
	int		activ_opt;
	t_file	*file_list;
	char	**files;

	if (((activ_opt = parse_argv_option(argc, argv, &files)) == -1))
		return (ft_printf("error\n"));
	printf_files(files);
	/*
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
	printf("folder : %s\n", files[0]);
	*/
	if (parse_folder(files[0], &file_list) == -1)
		return (ft_printf("error\n")); 
	print_folder(file_list);
	/*
	printf("\nmodif sort : \n");
	insert_sort(&file_list, modif_compare);
	print_folder(file_list);
	printf("\naccess sort : \n");
	insert_sort(&file_list, access_compare);
	print_folder(file_list);*/
	printf("\ncreation compare : \n");
	insert_sort(&file_list, creation_compare);
	print_folder(file_list);/*
	printf("\nascii sort : \n");
	insert_sort(&file_list, ascii_compare);
	print_folder(file_list);
	printf("\nsize sort : \n");
	insert_sort(&file_list, size_compare);
	print_folder(file_list);
	*/

}
