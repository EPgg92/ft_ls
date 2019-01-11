#include "ft_ls.h"

static int	ft_char_iequal(int letter_a, int letter_b)
{
	return (ft_toupper(letter_a) == ft_toupper(letter_b) ? 1 : 0);
}

int	alpha_cmp(t_file *f_one, t_file *f_two)
{
	int index;
	char *fname_one;
	char *fname_two;

	fname_one = f_one->name;
	fname_two = f_two->name;
	index = 0;
	if (*(fname_one) == '.')
		fname_one++;
	else if (*(fname_two) == '.')
		fname_two++;
	while (ft_char_iequal(fname_one[index], fname_two[index]) &&\
		fname_one[index] && fname_two[index])
		index++;
	if (!fname_one[index] && !fname_two[index])
		return (0);
	else if (ft_isalnum(fname_one[index]) && ft_isalnum(fname_two[index]))
		return (ft_toupper(fname_one[index]) -\
			ft_toupper(fname_two[index]));
	else if (!ft_isalnum(fname_one[index]) && !ft_isalnum(fname_two[index]))
		return (fname_one[index] - fname_two[index]);
	else
	{
		if (!ft_isalnum(fname_one[index]))
			return (-1);
		else
			return (1);
	}
}

int	modif_time_cmp(t_file *f_one, t_file *f_two)
{

	#define MODIF_TIME(file) file->data->st_mtim.tv_sec
	if (MODIF_TIME(f_one) > MODIF_TIME(f_two))
		return (-1);
	else if (MODIF_TIME(f_one) == MODIF_TIME(f_two))
		return (0);
	else
		return (1);
}

int	size_cmp(t_file *f_one, t_file *f_two)
{
	long diff;

	diff = f_one->data->st_size - f_two->data->st_size; 
	printf("Compare : %ld   with   %ld \n", f_one->data->st_size, f_two->data->st_size);
	if (diff == 0)
		return (0);
	else
		return (diff < 0 ? -1 : 1);
}
