#include "libopt.h"
// Format : "%s %xd %xs %xs %xd %s" + file

char		*field_formating(int value, char specifier)
{
	char	*value_str;
	char	*format;
	int		nbr_len

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

char		*add_field(char *old_format, int value, char specifier, int space)
{
	char	*filled_field;

	if (!(filled_field = field_formating(value, specifier)))
		return (ft_strdel_out(old_format, 0));
	if (space)
		if (!(old_format = ft_fstrjoin(old_format, " ", 1, 0)))
			return (NULL);
	return (ft_fstrjoin(old_format, filled_str, 1, 1));
}

char		*long_format(STRUCT_MAX, char *curr_format)
{
	char	*additional_str;

	if (!(additional_str = ft_strdup("%s ")))
		return (NULL);
	if (!(additional_str = add_field(additional_str, STRUCT_MAX.links, 'd', 1)))
		return (NULL);
	if (!(additional_str = add_field(additional_str, STRUCT_MAX.uid_len, 's', 1)))
		return (NULL);
	if (!(additional_str = add_field(additional_str, STRUCT_MAX.gid_len, 's', 1)))
		return (NULL);
	if (!(additional_str = add_field(additional_str, STRUCT_MAX.size_len, 'd', 1)))
		return (NULL);
	if (!(additional_str = ft_fstrjoin(additional_str, "%s ", 1, 0)))
		return (NULL);
	return (ft_fstrjoin(additional_str, curr_format, 1, 0));
}

char		*o_long_format(STRUCT_MAX, char *curr_format)
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
	ft_strmove(specifier, ft_strchar(specifier, '%'));
	return (curr_format);
}


char		*file_format(t_head_optn *options)
{
	char	*format;
	char	*tmp_field;

	if (!(format = (char *)malloc(sizeof(char) * 3)))
		return (NULL);
	ft_strcpy(format, "%s");
}
