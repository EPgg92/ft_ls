#include "ft_ls.h"

/*
** one_print:
**
** Using ft_printf for -1 option.
*/

void		one_print(t_file_head *head_file)
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

/*
** m_print:
**
** Using ft_printf for -m option.
*/

void		m_print(t_file_head *head_file)
{
	t_file		*file_list;
	int			printed;

	file_list = head_file->work_list;
	printed = 0;
	while (file_list)
	{
		if (printed + file_list->file_len + 2 > head_file->window_width)
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

/*
** print_each:
**
** In a chained list of t_file, print the filename of an element each
** range element.
*/

static void	print_each(t_file *file_list, char *pattern, int range)
{
	int index;

	index = 0;
	while (file_list)
	{
		if (index == 0)
			ft_printf(pattern, file_list->filename);
		index++;
		if (index == range)
		{
			ft_printf(" ");
			index = 0;
		}
		file_list = file_list->next;
	}
}

/*
** basic_print:
**
** Printing setted up by default, column printing.
*/

void		basic_print(t_file_head *head_file)
{
	int		term_width;
	int		file_by_line;
	int		nb_col;
	t_file	*file_list;
	int		index;

	if (head_file->files_number == 0 || (term_width = get_window_width()) == -1)
		return ;
	file_by_line = term_width / (head_file->len_filename + 1);
	if (file_by_line == 0)
	{
		one_print(head_file);
		return ;
	}
	nb_col = head_file->files_number / file_by_line;
	if (head_file->files_number % file_by_line != 0)
		nb_col++;
	file_list = head_file->work_list;
	index = 0;
	while (index++ < nb_col)
	{
		print_each(file_list, head_file->print_pattern, nb_col);
		ft_printf("\n");
		file_list = file_list->next;
	}
}
