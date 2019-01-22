#include "ft_ls.h"


int format_date(int active_opt, t_file *folder)
{
	time_t	date;
	char	*str_date;

	if (active_opt & T_MIN)
		date = folder->info->st_mtimespec.tv_sec;
	else if (active_opt & U_MAJ)
		date = folder->info->st_birthtimespec.tv_sec;
	else if (active_opt & U_MIN)
		date = folder->info->st_atimespec.tv_sec;
	str_date = ctime(&date);
	ft_strreplace(str_date, '\n', '\0');
	if (1) // C faux
		ft_memmove(str_date + 16 , str_date + 19 , 4);
	else
		str_date[16] = '\0';
	folder->modification_time = str_date;
	return(0);

}



void	select_sort(int active_opt, t_file **folder)
{
	format_date(active_opt, *folder);
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


void l_print(t_file_head *head_file)
{
	t_file	*file_list;

	file_list = head_file->work_list;
	while (file_list)
	{
		ft_printf(head_file->print_pattern, file_list->right, file_list->info->st_nlink,
		file_list->pw_name, file_list->gr_name, file_list->info->st_size,
		file_list->modification_time, file_list->filename);
		file_list = file_list->next;
		ft_printf("\n");
	}
	ft_printf("test\n");
}

void o_print(t_file_head *head_file)
{
	t_file	*file_list;

	file_list = head_file->work_list;
	while (file_list)
	{
		ft_printf(head_file->print_pattern, file_list->right, file_list->info->st_nlink,
		file_list->pw_name, file_list->info->st_size,
		file_list->modification_time, file_list->filename);
		file_list = file_list->next;
		ft_printf("\n");
	}
}

void	one_print(t_file_head *head_file)
{
	t_file	*file_list;

	file_list = head_file->work_list;
	while (file_list)
	{
		ft_printf(head_file->print_pattern, file_list->filename);
		file_list = file_list->next;
		ft_printf("\n");
	}
}

void 		m_print(t_file_head *head_file)
{
	t_file		*file_list;
	int 		printed;

	file_list = head_file->work_list;
	printed = 0;
	while (file_list)
	{
		if (printed + file_list->file_len > head_file->window_width)
		{
			printed = 0;
			ft_printf("\n");
		}
		else
		{
			if (!file_list->next)
				ft_printf("%s\n", file_list->filename);
			else
				printed += ft_printf("%s, ", file_list->filename);
		}
		file_list = file_list->next;
	}
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
