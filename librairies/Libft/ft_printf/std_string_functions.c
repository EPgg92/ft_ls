/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   std_string_functions.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:25:24 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 13:14:12 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <sys/stat.h>

/*
** get functions to get arguments from va_args and perform specfic routine:
**
** get_s : get char * type
** get_c : get char
*/

char	*get_s(va_list args, t_prt_opt *format_options, int *octets)
{
	char	*value;

	value = va_arg(args, char *);
	value = value ? ft_strdup(value) : ft_strdup("(null)");
	if (!value)
		return (NULL);
	*octets = ft_strlen(value);
	if (format_options->precision >= 0 && *octets > format_options->precision)
	{
		*octets = format_options->precision;
		ft_strclear(value, format_options->precision);
	}
	return (value);
}

char	*get_c(va_list args, t_prt_opt *format_options, int *octets)
{
	char	value;
	char	*formatted_str;

	UNUSED(format_options);
	value = va_arg(args, int);
	if (!(formatted_str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	formatted_str[0] = (char)value;
	formatted_str[1] = '\0';
	*octets = 1;
	return (formatted_str);
}
