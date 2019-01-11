/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 07:51:31 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:58:57 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_count :
**
** Count the number of element separated by a given charset.
*/

size_t		ft_count(const char *str, const char *charset)
{
	int		in_elem;
	size_t	counter;

	counter = 0;
	in_elem = 0;
	while (*str)
	{
		if (in_elem == 0 && ft_incharset(*str, charset) == 0)
		{
			in_elem = 1;
			counter++;
		}
		else if (in_elem == 1 && ft_incharset(*str, charset) == 1)
			in_elem = 0;
		str++;
	}
	return (counter);
}
