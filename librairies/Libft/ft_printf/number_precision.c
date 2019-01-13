/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   number_precision.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 16:05:56 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:06:11 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** set_number_precision:
**
** Check with the precision if the formated string need to be filled
** with '0'.
** Create the new string if needed.
**
** return value:
** - 1 if precision is set well.
** - -1 if an error occur.
** Change *formated_str address if the string changed.
*/

int		set_number_precision(char **formated_str, int precision)
{
	int		len;
	char	*filled_str;
	int		diff;

	len = ft_strlen(*formated_str);
	filled_str = NULL;
	if (precision > len)
	{
		if (!(filled_str = (char *)malloc(sizeof(char) * (precision + 1))))
		{
			ft_strdel(formated_str);
			return (-1);
		}
		diff = precision - len;
		ft_memset(filled_str, '0', diff);
		ft_strcpy(filled_str + diff, *formated_str);
		ft_strdel(formated_str);
		*formated_str = filled_str;
	}
	return (1);
}
