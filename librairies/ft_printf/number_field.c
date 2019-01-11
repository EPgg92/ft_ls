/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   number_field.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:47:40 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:47:42 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** left_adjust:
**
** Fill the field on the left is the - flag is active.
*/

void	left_adjust(char *new_form, char *old_str, int old_len, t_prt_opt *opt)
{
	int	diff;

	diff = opt->field - old_len;
	ft_strcpy(new_form, old_str);
	ft_memset(new_form + old_len, ' ', diff);
	new_form[old_len + diff] = '\0';
}

/*
** right_adjust_base:
**
** Fill the field of a number in octal or hexadecimal when the 0 flag is set
** Will copy the string depending of the # flag
*/

void	right_adjust_base(char *new_format, char *old_str, int old_len, \
		t_prt_opt *option)
{
	int	diff;
	int	hashtag_active;

	diff = option->field - old_len;
	hashtag_active = option->flag->hashtag;
	if (ft_incharset(option->specifier, "xXp") && hashtag_active)
	{
		ft_strncpy(new_format, old_str, 2);
		new_format += 2;
		old_str += 2;
	}
	else if (ft_incharset(option->specifier, "oO") && hashtag_active)
		ft_strncpy(new_format++, old_str++, 1);
	ft_memset(new_format, '0', diff);
	ft_strcpy(new_format + diff, old_str);
}

/*
** rigth_adjust:
**
** Fill the field on the left. Use the 0 flag to choose the filling character
*/

void	right_adjust(char *new_format, char *old_str, int old_len, \
		t_prt_opt *option)
{
	char	fill_char;
	int		diff;

	diff = option->field - old_len;
	if (ft_incharset(*old_str, "-+ ") && option->flag->zero)
		*new_format++ = *old_str++;
	fill_char = option->flag->zero ? '0' : ' ';
	ft_memset(new_format, fill_char, diff);
	ft_strcpy(new_format + diff, old_str);
}

/*
** set_nbfield:
**
** Check if the current formated string is shorter than the desired field.
** If the field is longer, fill it with specified characters in flags.
*/

int		set_nbfield(t_prt_opt *option, char **formated_str, int *octets)
{
	char	*new_str;

	if (*octets < (int)option->field)
	{
		if (!(new_str = (char *)malloc(sizeof(char) * (option->field + 1))))
			return (ft_strdel_out(formated_str, 0));
		if (option->flag->negativ)
			left_adjust(new_str, *formated_str, *octets, option);
		else
		{
			if (option->flag->zero && ft_incharset(option->specifier, "xXoOp"))
				right_adjust_base(new_str, *formated_str, *octets, option);
			else
				right_adjust(new_str, *formated_str, *octets, option);
		}
		*octets = option->field;
		ft_strdel(formated_str);
		*formated_str = new_str;
	}
	return (1);
}
