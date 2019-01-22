#include "ft_ls.h"
// Format : "%s %xd %xs %xs %xd %s" + file

static char	*field_formating(int value, char specifier)
{
	char	*value_str;
	char	*format;
	int		nbr_len;

	if (!(value_str = ft_itoa(value)))
		return (NULL);
	nbr_len = ft_strlen(value_str);
	if (!(format = (char *)malloc(sizeof(char) * (nbr_len + 3))))
		return (NULL);
	format[0] = '%';
	ft_strcpy(format + 1, value_str);
	format[1 + nbr_len] = specifier;
	format[2 + nbr_len] = '\0';
	return (format);
}

static char	*add_field(char **old_format, int value, char specifier, int space)
{
	char	*filled_field;
	char	*space_str;

	if (!(filled_field = field_formating(value, specifier)))
	{
		ft_strdel(old_format);
		return (NULL);
	}
	if (!(filled_field = ft_fstrjoin(old_format, &filled_field, 1, 1)))
		return (NULL);
	space_str = " ";
	if (space)
		return (ft_fstrjoin(&filled_field, &space_str, 1, 0));
	return (filled_field);
}

static char	*long_format(t_file_head *head, char *curr_format)
{
	char	*additional_str;
	char	*tmp_str;

	if (!(additional_str = ft_strdup("%s ")))
		return (NULL);
	if (!(additional_str = add_field(&additional_str, head->len_symlink, 'd', 1)))
		return (NULL);
	if (!(additional_str = add_field(&additional_str, head->len_user, 's', 1)))
		return (NULL);
	if (!(additional_str = add_field(&additional_str, head->len_group, 's', 1)))
		return (NULL);
	if (!(additional_str = add_field(&additional_str, head->len_size, 'd', 1)))
		return (NULL);
	tmp_str = "%s ";
	if (!(additional_str = ft_fstrjoin(&additional_str, &tmp_str, 1, 0)))
		return (NULL);
	return (ft_fstrjoin(&additional_str, &curr_format, 1, 0));
}

static char	*o_long_format(char *curr_format)
{
	int		index;
	char	*specifier;

	index = 0;
	specifier = curr_format;
	while (index < 3)
	{
		index++;
		specifier = ft_strchr(specifier, '%');
	}
	ft_strmove(specifier, ft_strchr(specifier, '%'));
	return (curr_format);
}


char		*get_printing_pattern(t_file_head *head_file)
{
	char	*format;

	if (!(format = (char *)malloc(sizeof(char) * 3)))
		return (NULL);
	ft_strcpy(format, "%s");
	if (head_file->opts & L_MIN)
		long_format(head_file, format);
	if (head_file->opts & O_MIN)
		o_long_format(format);
	head_file->file_pattern = format;
	return (format);
}
