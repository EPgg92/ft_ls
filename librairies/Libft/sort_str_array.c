/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_str_array.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 15:58:05 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 15:58:19 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int			array_len(char **array)
{
	int		index;

	index = 0;
	while (array[index])
		index++;
	return (index);
}

void				sort_str_array(char **strings, \
							int (cmp_fct)(const char *, const char  *))
{
	int		len;
	int		index;

	len = array_len(strings);
	while (len >= 2)
	{
		index = 0;
		while (index < len - 1)
		{
			if (cmp_fct(strings[index], strings[index + 1]) > 0)
				ft_strswap(strings + index, strings + index + 1);
			index++;
		}
		len--;
	}
}
