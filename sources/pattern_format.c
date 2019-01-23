#include "ft_ls.h"
// Format : "%s %xd %xs %xs %xd %s" + file
#define DBL_SPACE	0b100
#define SPACE_OPT	0b10
#define ALIGN_OPT	0b1
#define NO_OPT		0b0

static char	*field_formating(int value, char specifier, int options)
{
	char	*value_str;
	char	*format;
	int		nbr_len;
	int		alloc_size;

	if (!(value_str = ft_itoa(value)))
		return (NULL);
	alloc_size = options & ALIGN_OPT ? 4 : 3;
	nbr_len = ft_strlen(value_str);
	if (!(format = (char *)malloc(sizeof(char) * (nbr_len + alloc_size))))
		return (NULL);
	format[0] = '%';
	if (options & ALIGN_OPT)
		format[1] = '-';
	ft_strcpy(format + 1 + ((options & ALIGN_OPT) != 0), value_str);
	format[1 + nbr_len + ((options & ALIGN_OPT) != 0)] = specifier;
	format[2 + nbr_len + ((options & ALIGN_OPT) != 0)] = '\0';
	return (format);
}

static char	*add_field(char **old_format, int value, char specifier, int options)
{
	char	*filled_field;
	char	*space_str;

	if (!(filled_field = field_formating(value, specifier, options)))
	{
		ft_strdel(old_format);
		return (NULL);
	}
	if (!(filled_field = ft_fstrjoin(old_format, &filled_field, 1, 1)))
		return (NULL);
	if (options & SPACE_OPT || options & DBL_SPACE)
	{

		space_str = options & DBL_SPACE ? "  " : " ";
		return (ft_fstrjoin(&filled_field, &space_str, 1, 0));
	}
	return (filled_field);
}

static char	*long_format(t_file_head *head, char *curr_format)
{
	char	*additional_str;
	char	*tmp_str;

	if (!(additional_str = ft_strdup("%s ")))
		return (NULL);
	if (!(additional_str = add_field(&additional_str, head->len_symlink, 'd', SPACE_OPT)))
		return (NULL);
	if (!(additional_str = add_field(&additional_str, head->len_user, 's', DBL_SPACE | ALIGN_OPT)))
		return (NULL);
	if (!(additional_str = add_field(&additional_str, head->len_group, 's', SPACE_OPT | ALIGN_OPT)))
		return (NULL);
	if (!(additional_str = add_field(&additional_str, head->len_size, 'd', SPACE_OPT )))
		return (NULL);
	tmp_str = "%s ";
	if (!(additional_str = ft_fstrjoin(&additional_str, &tmp_str, 1, NO_OPT)))
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
		specifier = ft_strchr(specifier + 1, '%');
	}
	ft_strmove(specifier, ft_strchr(specifier + 1, '%'));
	return (curr_format);
}

static char		*format_filebase(t_file_head *head_file)
{

	if (head_file->opts & L_MIN || head_file->opts & O_MIN ||
		head_file->opts & M_MIN)
		return (ft_strdup("%s"));
	else
		return (field_formating(head_file->len_filename, 's', NO_OPT));
}

char		*get_printing_pattern(t_file_head *head_file)
{
	char	*format;

	if (!(format = format_filebase(head_file)))
		return (NULL);
	if (head_file->opts & L_MIN)
		format = long_format(head_file, format);
	if (head_file->opts & O_MIN)
		format = o_long_format(format);
	head_file->print_pattern = format;
	return (format);
}
