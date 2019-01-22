#include "ft_ls.h"

void	select_sort(int active_opt, t_file **folder)
{
	if (U_MIN & active_opt)
		insert_sort(folder, access_compare);
	else if (U_MAJ & active_opt)
		insert_sort(folder, creation_compare);
	else if (S_MAJ & active_opt)
		insert_sort(folder, size_compare);
	else if (T_MIN & active_opt)
		insert_sort(folder, modif_compare);
	else
		insert_sort(folder, ascii_compare);
	if (R_MIN & active_opt)
		reverse_files(folder);
}

int		select_print(int active_opt, t_file **folder)
{
	folder = NULL;
	if (F_MAJ & active_opt)
		if (modify_filename(folder) == -1)
			return (-1);
	if (O_MIN & active_opt)
		; //longformat_nogroup_print(folder);
	else if (L_MIN & active_opt)
		; //longformat_print(folder);
	else if (M_MIN & active_opt)
		; //comma_print(folder);
	else if (OPT_1 & active_opt)
		; //one_colum_print(folder);
	else
		; //simple_print(folder);
	return (1);
}
