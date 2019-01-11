/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flags_parse.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:03:36 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:03:42 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** remove_uncompatible_flags:
**
** Set to 0 all flags which are override by an other one.
*/

void	remove_uncompatible_flags(t_flags *flags)
{
	if (flags->negativ)
		flags->zero = 0;
	if (flags->positiv)
		flags->space = 0;
}

/*
** parse_flags:
**
** Parse our format string and set up all avaible flags
** into our t_prt_opt->flag element.
** Remove uncompatible flags when the parsing is over.
*/

void	parse_flags(char **format, t_flags *flags)
{
	flags->positiv = 0;
	flags->negativ = 0;
	flags->zero = 0;
	flags->hashtag = 0;
	flags->space = 0;
	while (is_flag(**format))
	{
		if (**format == '+')
			flags->positiv = 1;
		else if (**format == '-')
			flags->negativ = 1;
		else if (**format == '0')
			flags->zero = 1;
		else if (**format == '#')
			flags->hashtag = 1;
		else if (**format == ' ')
			flags->space = 1;
		(*format)++;
	}
	remove_uncompatible_flags(flags);
}
