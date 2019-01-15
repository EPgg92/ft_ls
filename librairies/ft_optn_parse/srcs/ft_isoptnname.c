#include "../includes/libopt.h"

/*
** ft_isoptname:
**
** check if the part after -- of a long option
** is an allowed variable name.
*/

static int		ft_isoptname(const char *string, t_head_optn *head)
{
	while(*(head->opt_long))
		if (ft_strcmp(string, *(head->opt_long)) == 0)
			return (0);
	return (1);

	// if (!*string)
	// 	return (0);
	// if (ft_isalpha(*string) == 0)
	// 	return (0);
	// while (ft_isalnum(*string) || *string == '_' || *string == '-')
	// 	string++;
	// return (!*string ? 1 : 0);
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

int				ft_is_optn(const char *string, t_head_optn *head)
{
	int i;

	if (ft_start_with(string, "--"))
		return (ft_isoptname(string, head));
	i = 0;
	while (string[++i])
		if ((ft_strchr(head->opt_sing, string[i]) || \
			ft_strchr(head->opt_arg, string[i])) == 0)
			return (0);
	return (1);
}
