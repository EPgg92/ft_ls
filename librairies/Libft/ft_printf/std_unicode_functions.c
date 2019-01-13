/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   std_unicode_functions.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:15:31 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:56:06 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** get function for va_arg, using to display unicode strings:
**
** get_big_c : get wchar_t
** get_big_s : get wchar_t *
*/

static void	*check_precision(wchar_t **wstr, t_prt_opt *options, int *octets)
{
	wchar_t	*new_format;
	wchar_t	new_len;
	wchar_t	*tmp_wstr;
	int		index;

	if (options->precision >= 0 && *octets > options->precision)
	{
		tmp_wstr = *wstr;
		if (!(new_format = malloc(sizeof(wchar_t) * (options->precision + 1))))
			return (ft_wstrdel(wstr));
		new_len = determine_bytes(*tmp_wstr);
		index = 0;
		while (new_len <= options->precision)
		{
			new_format[index++] = *tmp_wstr++;
			new_len += determine_bytes(*tmp_wstr);
		}
		new_format[index] = 0;
		new_len -= determine_bytes(*tmp_wstr);
		*octets = new_len;
		ft_wstrdel(wstr);
		*wstr = new_format;
	}
	return (NULL);
}

wchar_t		*get_big_s(va_list args, t_prt_opt *options, int *octets)
{
	wchar_t *value;

	UNUSED(options);
	value = va_arg(args, wchar_t *);
	*octets += str_byteslen(value);
	value = ft_wstrdup(value);
	check_precision(&value, options, octets);
	return (value);
}

wchar_t		*get_big_c(va_list args, t_prt_opt *options, int *octets)
{
	wchar_t value;
	wchar_t *string;

	UNUSED(options);
	value = va_arg(args, wchar_t);
	*octets += determine_bytes(value);
	string = (wchar_t *)malloc(sizeof(wchar_t) * 2);
	if (!string)
		return (NULL);
	string[0] = value;
	string[1] = 0;
	return (string);
}
