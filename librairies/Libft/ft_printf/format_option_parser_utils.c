/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_option_parser_utils.c                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 17:28:52 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 17:34:19 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** parse_precision:
**
** Set up the t_prt_opt->precision attribute. If the option is available,
** format in incremented.
** Override flag 0 if needed.
*/

void			parse_precision(char **format, t_prt_opt *options)
{
	options->precision = -1;
	if (**format == '.')
	{
		(*format)++;
		options->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (options->precision >= 0)
		options->flag->zero = 0;
}

/*
** parse_field:
**
** Set up the t_prt_opt->field attribute. If the option is available,
** format is incremented.
*/

void			parse_field(char **format, t_prt_opt *options)
{
	options->field = 0;
	if (ft_isdigit(**format))
	{
		options->field = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

/*
** modifier_fix:
**
** utils of parse_modifier function. Will fix the modifier attribute
** and increment the format string of the right len.
*/

static void		modifier_fix(char **format, char *pattern, t_prt_opt *option)
{
	option->modifier = pattern;
	(*format) += ft_strlen(pattern);
}

/*
** parse_modifier:
**
** Set up the t_prt_opt->modifier attribute;
*/

void			parse_modifier(char **format, t_prt_opt *options)
{
	options->modifier = "";
	if (ft_strnequ(*format, "hh", 2))
		modifier_fix(format, "hh", options);
	if (ft_strnequ(*format, "h", 1))
		modifier_fix(format, "h", options);
	if (ft_strnequ(*format, "ll", 2))
		modifier_fix(format, "ll", options);
	if (ft_strnequ(*format, "l", 1))
		modifier_fix(format, "l", options);
}
