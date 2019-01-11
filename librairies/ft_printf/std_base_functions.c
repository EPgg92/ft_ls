/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   std_base_functions.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:25:44 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 18:12:04 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

char	*get_base(va_list args, t_prt_opt *options, int *octets)
{
	unsigned int	value;
	char			*format_str;
	char			*fill_char;
	char			*base;

	value = va_arg(args, unsigned int);
	set_base_choice(options, &fill_char, &base);
	if (!(format_str = ft_itoabase(value, base)))
		return (NULL);
	if (!(format_str = base_routine(options, format_str, fill_char)))
		return (NULL);
	*octets += ft_strlen(format_str);
	return (format_str);
}

char	*get_lbase(va_list args, t_prt_opt *options, int *octets)
{
	if (LLONG_MAX == LONG_MAX)
		return (get_llbase(args, options, octets));
	else
		return (get_base(args, options, octets));
}

char	*get_llbase(va_list args, t_prt_opt *options, int *octets)
{
	unsigned long long int	value;
	char					*format_str;
	char					*fill_char;
	char					*base;

	value = va_arg(args, unsigned long long int);
	set_base_choice(options, &fill_char, &base);
	if (!(format_str = ft_ltoabase(value, base)))
		return (NULL);
	if (!(format_str = base_routine(options, format_str, fill_char)))
		return (NULL);
	*octets += ft_strlen(format_str);
	return (format_str);
}

char	*get_h_hhbase(va_list args, t_prt_opt *options, int *octets)
{
	unsigned int	value;
	char			*format_str;
	char			*fill_char;
	char			*base;

	value = va_arg(args, unsigned int);
	if (ft_strequ("hh", options->modifier))
		value = (unsigned char)value;
	else
		value = (short unsigned)value;
	set_base_choice(options, &fill_char, &base);
	if (!(format_str = ft_itoabase(value, base)))
		return (NULL);
	if (!(format_str = base_routine(options, format_str, fill_char)))
		return (NULL);
	*octets += ft_strlen(format_str);
	return (format_str);
}
