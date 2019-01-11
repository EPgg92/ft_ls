/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_option_parser.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:05:37 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 17:32:46 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** check_identical_specifier:
**
** Join under the same specifier different specifier with the same behavior.
*/

void			check_identical_specifier(t_prt_opt *format_options)
{
	if (format_options->specifier == 'i')
		format_options->specifier = 'd';
}

/*
** parse_option:
**
** Called whenever a unescaped % symbol is found. Fill up formatting option
** in a t_prt_opt structure.
**
** return value:
** - 1 if option have beend parsed correctly
** - 0 if given option are invalid and no format should be printed
** - -1 if a memory allocation error occur.
**
** pointers effects:
** If the option format is valid, the *format string will be incremented to
** the specifier. Otherwise, '%' will be print and *format will be incremented
** of 1.
*/

int				parse_option(char **format, t_prt_opt **format_option)
{
	char *start;
	char *specifier;

	start = *format;
	(*format)++;
	if (!*format_option && !(*format_option = alloc_option()))
		return (-1);
	if (!(specifier = ft_fstrchr(*format, is_specifier)))
		return (0);
	parse_flags(format, (*format_option)->flag);
	parse_field(format, *format_option);
	parse_precision(format, *format_option);
	parse_modifier(format, *format_option);
	if (*format != specifier)
	{
		*format = start;
		return (0);
	}
	(*format_option)->specifier = *specifier;
	check_identical_specifier(*format_option);
	set_category(*format_option);
	if (!set_full_specifier(*format_option))
		return (-1);
	return (1);
}
