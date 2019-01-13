/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unicode_field.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:02:47 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:02:51 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** adjust_left:
**
** Fill up the field and adjust string on the left when - flag is specified.
*/

static void		adjust_left(wchar_t *new_wstr, wchar_t *old_wstr, int diff, \
		int oldlen)
{
	ft_wstrcpy(new_wstr, old_wstr);
	new_wstr += oldlen;
	while (diff--)
		*new_wstr++ = ' ';
	*new_wstr = '\0';
}

/*
** adjust_right:
**
** Fill up the field with string right adjusted.
*/

static void		adjust_right(wchar_t *new_str, wchar_t *old_wstr, int diff)
{
	while (diff--)
		*new_str++ = L' ';
	ft_wstrcpy(new_str, old_wstr);
}

/*
** set_unicode_field:
**
** Check for the given unicode string and specified option
** if the field have to be filled.
** Adjust it according to the - flag.
**
** return value:
** - 1 if the field is fill properly
** - -1 if an malloc error occur.
*/

int				set_unicode_field(t_prt_opt *option, wchar_t **wstr, \
		int *octets)
{
	int		diff;
	int		old_len;
	wchar_t	*new_wstr;

	diff = option->field - *octets;
	if (diff > 0)
	{
		old_len = ft_wstrlen(*wstr);
		new_wstr = (wchar_t *)malloc(sizeof(wchar_t) * (old_len + diff + 1));
		if (!new_wstr)
		{
			ft_wstrdel(wstr);
			return (-1);
		}
		if (option->flag->negativ)
			adjust_left(new_wstr, *wstr, diff, old_len);
		else
			adjust_right(new_wstr, *wstr, diff);
		ft_wstrdel(wstr);
		*octets = option->field;
		*wstr = new_wstr;
	}
	return (1);
}
