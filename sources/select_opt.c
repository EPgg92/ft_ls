#include "ft_ls.h"

void	select_sort(int active_opt, t_file **folder)
{
	format_all_date(active_opt, *folder);
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

int 			get_window_width(void)
{
	struct winsize w;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1)
		return (-1);
	return (w.ws_col);
}

void 			print_manager(t_file_head *head_file, print_mode prt_fct, char *folder)
{
	if (head_file->file_printed >= 1)
		ft_printf("\n");
	head_file->file_printed++;
	if (head_file->print_foldname)
		ft_printf("%s:\n", folder);
	prt_fct(head_file);
}


int		select_print(t_file_head *head, char *folder)
{
	if ((head->window_width = get_window_width()) == -1)
		return (-1);
	head->files_number = t_file_list_len(head->work_list);
	if (F_MAJ & head->opts)
		if (modify_filename(&head->work_list) == -1)
			return (-1);
	if (O_MIN & head->opts)
		print_manager(head, o_print, folder);
	else if (L_MIN & head->opts)
		print_manager(head, l_print, folder);
	else if (M_MIN & head->opts)
		print_manager(head, m_print, folder);
	else if (OPT_1 & head->opts)
		print_manager(head, one_print, folder);
	/*else
		; //simple_print(folder);*/
	return (1);
}
