/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string_field.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:07:00 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:07:43 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void		adjust_left(char *new_format, char *old_format, int diff, \
		int *curr_len)
{
	ft_strcpy(new_format, old_format);
	ft_memset(new_format + *curr_len, ' ', diff);
	*curr_len += diff;
	new_format[*curr_len] = '\0';
}

static void		adjust_right(char *new_format, char *old_format, int diff, \
		int *curr_len)
{
	ft_memset(new_format, ' ', diff);
	ft_strcpy(new_format + diff, old_format);
	*curr_len += diff;
}

int				set_strfield(t_prt_opt *options, char **format_str, int *octets)
{
	char	*filled_str;
	int		diff;

	diff = options->field - *octets;
	if (diff <= 0)
		return (1);
	if (!(filled_str = (char *)malloc(sizeof(char) * (options->field + 1))))
	{
		ft_strdel(format_str);
		return (0);
	}
	if (options->flag->negativ)
		adjust_left(filled_str, *format_str, diff, octets);
	else
		adjust_right(filled_str, *format_str, diff, octets);
	ft_strdel(format_str);
	*format_str = filled_str;
	return (1);
}
