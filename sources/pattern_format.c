#include "ft_ls.h"

#define DBL_SPACE	0b100
#define SPACE_OPT	0b10
#define ALIGN_OPT	0b1
#define NO_OPT		0b0

/*
** field_formating:
**
** Create a string from of a specific specifier, with adding a field or an
** hyphen option.
**
** return value:
** - NULL if an allocation error occur, the formated string otherwise.
*/

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
	ft_strdel(&value_str);
	return (format);
}

/*
** add_field:
**
** Manage field adding on a % format. Make a concatenation of the old string
** with the newly created specifier. Add space at the end of the string
** as requested.
**
** return value:
** - NULL if an allocation error occur, the formated string otherwise.
*/

static char	*add_field(char **old_format, int value, char specifier, \
																	int options)
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

/*
** long_format:
**
** Prepare the pattern for the -l option.
** Look like : "%s %Xd %Xs  %Xs  %Xd %s %s", where X is a value.
**
** return value:
** - NULL if an allocation error occur, the newly created pattern otherwise
*/

static char	*long_format(t_file_head *head, char *curr_format)
{
	char	*additional_str;
	char	*tmp_str;

	if (!(additional_str = ft_strdup("%s ")))
		return (NULL);
	if (!(additional_str = add_field(&additional_str, head->len_symlink, 'd', \
														SPACE_OPT)))
		return (NULL);
	if (!(additional_str = add_field(&additional_str, head->len_user, 's', \
														DBL_SPACE | ALIGN_OPT)))
		return (NULL);
	if (!(additional_str = add_field(&additional_str, head->len_group, 's', \
														DBL_SPACE | ALIGN_OPT)))
		return (NULL);
	if (!(additional_str = add_field(&additional_str, head->len_size, 'd', \
														SPACE_OPT)))
		return (NULL);
	tmp_str = "%s ";
	if (!(additional_str = ft_fstrjoin(&additional_str, &tmp_str, 1, NO_OPT)))
		return (NULL);
	return (ft_fstrjoin(&additional_str, &curr_format, 1, 1));
}

/*
** o_long_format:
**
** Prepare the pattern for printing with the -o option. Use a pattern create
** by the long_format function and strip the group.
*/

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

/*
** get_printing_pattern:
**
** Format a printf pattern for a file according to the ls options.
** Store this pattern in the t_file_head structure.
**
** return value:
** - NULL if a malloc error occur
** - The allocated string on success.
*/

char		*get_printing_pattern(t_file_head *head_file)
{
	char	*format;

	if (head_file->opts & L_MIN || head_file->opts & O_MIN ||
		head_file->opts & M_MIN || head_file->opts & OPT_1)
		format = ft_strdup("%s");
	else
		format = field_formating(head_file->len_filename, 's', ALIGN_OPT);
	if (!format)
		return (NULL);
	if (head_file->opts & L_MIN)
		format = long_format(head_file, format);
	if (!format)
		return (NULL);
	if (head_file->opts & O_MIN)
		format = o_long_format(format);
	head_file->print_pattern = format;
	return (format);
}
