/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   std_integer_functions.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:27:56 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 10:48:03 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** integer_routine:
**
** Perform action to format string according to differents flags.
** Common for each type (long long, long, int...).
** Set up the precision, and act depending of "-+ " options.
*/

char	*integer_routine(int negativ, char *format_str, t_prt_opt *options)
{
	char *fill_char;

	if (negativ)
		ft_strmove(format_str, format_str + 1);
	if (set_number_precision(&format_str, options->precision) == -1)
		return (NULL);
	if (negativ && (fill_char = "-"))
		if (!(format_str = ft_fstrjoin(&fill_char, &format_str, 0, 1)))
			return (NULL);
	if (options->flag->positiv && !negativ && (fill_char = "+"))
		if (!(format_str = ft_fstrjoin(&fill_char, &format_str, 0, 1)))
			return (NULL);
	if (options->flag->space && !negativ && (fill_char = " "))
		if (!(format_str = ft_fstrjoin(&fill_char, &format_str, 0, 1)))
			return (NULL);
	return (format_str);
}

/*
** get functions to get arguments from va_arg:
**
** get_d : get int
** get_ld : get long int
** get_lld : get long long int
** get_h_hhd : get int and cast it into short or char.
*/

char	*get_d(va_list args, t_prt_opt *options, int *octets)
{
	int		value;
	char	*format_str;

	value = va_arg(args, int);
	if (!(format_str = ft_itoa(value)))
		return (NULL);
	if (!(format_str = integer_routine(value < 0, format_str, options)))
		return (NULL);
	*octets += ft_strlen(format_str);
	return (format_str);
}

char	*get_ld(va_list args, t_prt_opt *options, int *octets)
{
	if (LLONG_MAX == LONG_MAX)
		return (get_lld(args, options, octets));
	else
		return (get_d(args, options, octets));
}

char	*get_lld(va_list args, t_prt_opt *options, int *octets)
{
	long long int	value;
	char			*format_str;

	value = va_arg(args, long long int);
	if (!(format_str = ft_lltoa(value)))
		return (NULL);
	if (!(format_str = integer_routine(value < 0, format_str, options)))
		return (NULL);
	*octets += ft_strlen(format_str);
	return (format_str);
}

char	*get_h_hhd(va_list args, t_prt_opt *options, int *octets)
{
	int		value;
	char	*format_str;

	value = va_arg(args, int);
	if (ft_strequ("hh", options->modifier))
		value = (char)value;
	else
		value = (short int)value;
	if (!(format_str = ft_itoa(value)))
		return (NULL);
	if (!(format_str = integer_routine(value < 0, format_str, options)))
		return (NULL);
	*octets += ft_strlen(format_str);
	return (format_str);
}
