#include "libopt.h"

/*
** ft_isoptname:
**
** check if the part after -- of a long option
** is an allowed variable name.
*/

static int		ft_isoptname(const char *string, t_head_optn *head)
{
	while(*(head->opt_long))
		if (ft_strcmp(string, (const char *)*head->opt_long) == 0)
			return (3);
	return (-1);
}

/*
** analyse_optn:
**
** Check if a string seem to be an option.
**
** Two steps :
** 1) see if it's a long name argument
** 2) see if a string is a short argument
**
** return value:
**		- 4 is a multiple option without arg
**		- 3 is a long option
**		- 2 is an option with arg
**		- 1 is an option without arg
**		- 0 is an argument
**		- -1 invalid option
*/

int				analyse_optn(const char *string, t_head_optn *head)
{
	int i;

	if (ft_start_with(string, "--"))
		return (ft_isoptname(string, head));
	if (ft_start_with(string, "-"))
	{
		if (ft_strnlen(string, 3) == 2 && ft_strchr(head->opt_arg, string[1]))
			return (2);
		i = 1;
		while (string[i])
			if (!ft_strchr(head->opt_sing, string[i++]))
				return (-1);
		return ((i < 2) ? 4 : 1);
	}
	return (0);
}
