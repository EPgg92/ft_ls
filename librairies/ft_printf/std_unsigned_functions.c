/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   std_unsigned_functions.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:14:19 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:14:37 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** get functions to get arguments from va_arg.
**
** get_u : Get unsigned int
** get_lu : Get long unsigned int
** get_llu : Get long long unsinged int
** get_h_hhu : Get unsigned int and cast into short or unsigned char
*/

char		*get_u(va_list args, t_prt_opt *options, int *octets)
{
	uintmax_t	value;
	char		*format_str;

	value = va_arg(args, unsigned int);
	if (!(format_str = ft_utoa(value)))
		return (NULL);
	if (set_number_precision(&format_str, options->precision) == -1)
		return (NULL);
	*octets += ft_strlen(format_str);
	return (format_str);
}

char		*get_lu(va_list args, t_prt_opt *options, int *octets)
{
	if (LONG_MAX == LLONG_MAX)
		return (get_llu(args, options, octets));
	else
		return (get_u(args, options, octets));
}

char		*get_llu(va_list args, t_prt_opt *options, int *octets)
{
	unsigned long long int	value;
	char					*format_str;

	value = va_arg(args, unsigned long long int);
	if (!(format_str = ft_llutoa(value)))
		return (NULL);
	if (set_number_precision(&format_str, options->precision) == -1)
		return (NULL);
	*octets += ft_strlen(format_str);
	return (format_str);
}

char		*get_h_hhu(va_list args, t_prt_opt *options, int *octets)
{
	unsigned long long int	value;
	char					*format_str;

	value = va_arg(args, unsigned int);
	if (ft_strequ("h", options->modifier))
		value = (short unsigned int)value;
	else
		value = (unsigned char)value;
	if (!(format_str = ft_itoa(value)))
		return (NULL);
	if (set_number_precision(&format_str, options->precision) == -1)
		return (NULL);
	*octets += ft_strlen(format_str);
	return (format_str);
}
