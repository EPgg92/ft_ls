/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move_strtab.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 16:48:16 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/13 16:48:22 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_move_strtab(char **tab, int len, int from, int to)
{
	int ascending;

	if (from >= len || to >= len || from == 0 || to == 0)
		return (0);
	ascending = from < to ? 1 : 0;
	if (ascending)
	{
		while (from < to)
		{
			ft_strswap(tab + from, tab + from + 1);
			from++;
		}
	}
	else
	{
		while (from > to)
		{
			ft_strswap(tab + from, tab + from - 1);
			from--;
		}
	}
	return (1);
}
