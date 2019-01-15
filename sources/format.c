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

char		*long_format(STRUCT_MAX)
{
	char	*additional_str;

	if (!(additional_str = ft_strdup("%s ")))
		return (NULL);
	tmp_field = field_formating(STRUCT_MAX.links, 'd');
	if (!tmp_field || ft_fstrjoin(additional_str
}



char		*file_format(t_head_optn *options)
{
	char	*format;
	char	*tmp_field;

	if (!(format = (char *)malloc(sizeof(char) * 3)))
		return (NULL);
	ft_strcpy(format, "%s");
}
