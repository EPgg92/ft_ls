/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   std_base_utils.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 17:36:22 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 17:38:44 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** get_function for va_arg, used for specifier with base (x, X, o):
**
** Each function call set_base_choice to select octal or hexadecimal mode.
**
** get_base: get an unsigned int
** get_lbase: get a long unsigned int
** get_llbase: get a long long unsigned int
** get_h_hhbase: get a unsigned int and cast it in short unsigned or char
*/

void	set_base_choice(t_prt_opt *options, char **fill_start, char **base)
{
	int capital;

	if (options->specifier == 'x' || options->specifier == 'X')
	{
		capital = options->specifier == 'X' ? 1 : 0;
		*fill_start = capital ? "0X" : "0x";
		*base = capital ? "0123456789ABCDEF" : "0123456789abcdef";
	}
	else
	{
		*fill_start = "0";
		*base = "01234567";
	}
}

/*
** base_routine:
**
** Set up precision and format the string according to different flag.
** Common to each type (long long, long, unsigned...)
*/

char	*base_routine(t_prt_opt *options, char *format_str, char *fill_char)
{
	if (set_number_precision(&format_str, options->precision) == -1)
		return (NULL);
	if (options->flag->hashtag)
	{
		if (!(options->specifier == 'o' && *format_str == '0'))
			if (!(format_str = ft_fstrjoin(&fill_char, &format_str, 0, 1)))
				return (NULL);
	}
	return (format_str);
}
