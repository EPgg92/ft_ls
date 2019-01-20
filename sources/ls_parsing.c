/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epoggio <epoggio@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:35:41 by epoggio      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 18:50:15 by epoggio     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** is_valid_opt:
**
** Analyse in an element of argv is an option, and check if this option
** is a option's charset.
*/

static int		is_valid_opt(char *str)
{
	int i;

	i = 0;
	if (str[i++] == '-' && ft_strnlen(str, 2) > 1)
	{
		while (str[i])
		{
			if (!ft_strchr(ALL_OPT, str[i]))
				return (i);
			i++;
		}
		return (0);
	}
	return (-1);
}

/*
** set_active_opt:
**
** From a given char, activate bit corresponding to the desired option.
** Override option if needed.
**
** return value:
** - formated byte containing options.
*/

static short	set_active_opt(short opt, char first)
{
	short	tmp;
	int		span;

	if (first != 'o')
	{
		tmp = 1;
		span = find_index(ALL_OPT, first);
		tmp <<= span;
	}
	else
		tmp = L_MIN | O_MIN;
	if (first == '1' || first == 'm' || first == 'l' || first == 'o')
		opt = opt & ~RESET_PRINT;
	else if (first == 'u' || first == 'U' || first == 'S')
		opt = opt & ~RESET_SORT;
	return (tmp | opt);
}

/*
** set_active_multi_opt:
**
** Parse an option string to store each caracter in our option byte.
** Call set_active_opt for each option letter.
*/

static short	set_active_multi_opt(short opt, char *opt_name)
{
	int		i;

	i = 1;
	while (opt_name[i])
		opt = set_active_opt(opt, opt_name[i++]);
	return (opt);
}

/*
** option_fill:
**
** Parse until a double hyphen (--) is found and store arguments files and also
** fill the option byte with set_active_multi_opt funciton.
** Display an error message if an option error occur.
*/

static int		option_fill(char ***argv, char **files_names, int *index)
{
	int		invalid_opt;
	int		active_opt;
	int		error;

	active_opt = 0;
	*argv += 1;
	error = 1;
	while (**argv && ft_strcmp(**argv, "--") && error)
	{
		if (((invalid_opt = is_valid_opt(**argv)) >= 0))
		{
			if (invalid_opt != 0)
				return (ft_printf("ls: illegal option -- %c\n", \
				(**argv)[invalid_opt]) ? -1 : -1);
				active_opt = set_active_multi_opt(active_opt, **argv);
		}
		else
		{
			error *= (files_names[*index] = ft_strdup(**argv)) == NULL ? 0 : 1;
			*index += 1;
		}
		*argv += 1;
	}
	*argv += (**argv != NULL && ft_strequ(**argv, "--")) ? 1 : 0;
	return (error == 0 ? free_str_array(&files_names, -1) : active_opt);
}

/*
** parse_argv_option:
**
** Use to parse argv in ft_ls program. Store all desired option in a single
** byte.
** Store also arguments (= files) in a char ** pointer.
** Check if all option are valid and display an error message if it's needed.
**
** return value:
** - -1 if an error occur, with malloc or an invalid argument.
** - a bit from 0 to x which store option. Use mask to analyse them.
*/

int				parse_argv_option(int argc, char **argv,
								char ***files_names)
{
	short	active_opt;
	int		index;
	int		error;

	active_opt = 0;
	index = 0;
	error = 1;
	if (!(*files_names = create_tab(argc)))
		return (-1);
	if ((active_opt = option_fill(&argv, *files_names, &index)) == -1)
		return (-1);
	while (*argv && error)
		error *= ((*files_names)[index++] = ft_strdup(*argv++)) == NULL ? 0 : 1;
	if ((*files_names)[0] == NULL && error)
		error *= ((*files_names)[0] = ft_strdup(".")) == NULL ? 0 : 1;
	return (error == 0 ? free_str_array(files_names, -1) : active_opt);
}
