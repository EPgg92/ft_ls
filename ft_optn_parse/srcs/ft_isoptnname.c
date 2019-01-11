
#include "libft.h"

/*
** ft_isoptname:
**
** check if the part after -- of a long option
** is an allowed variable name.
*/

static int		ft_isoptname(const char *string)
{
	if (!*string)
		return (0);
	if (ft_isalpha(*string) == 0)
		return (0);
	while (ft_isalnum(*string) || *string == '_' || *string == '-')
		string++;
	return (!*string ? 1 : 0);
}

/*
** ft_is_optn:
**
** Check if a string seem to be an option.
**
** Two steps :
** 1) see if a string is a short argument
** 2) see if it's a long name argument
*/

int				ft_is_optn(const char *string)
{
	if (ft_strnlen(string, 3) == 2 && ft_start_with(string, "-") \
		&& ft_isalpha(string[1]))
		return (1);
	if (ft_start_with(string, "--") && ft_isoptname(string + 2))
		return (1);
	return (0);
}
