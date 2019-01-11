/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nbrlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 16:12:24 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:12:49 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

size_t		ft_nbrlen(long long nbr)
{
	size_t		len;
	long long	divider;

	len = 0;
	if (nbr < 0)
		len++;
	else if (nbr == 0)
		return (1);
	if (nbr / 1000000000000000000 != 0)
		return (len + 19);
	divider = 1;
	while (nbr / divider)
	{
		divider *= 10;
		len++;
	}
	return (len);
}

size_t		ft_unbrlen(unsigned long long nbr)
{
	unsigned long long	dividor;
	int					len;

	dividor = ULONG_MAX - 8446744073709551615;
	if (nbr / dividor)
		return (20);
	else if (nbr == 0)
		return (1);
	len = 0;
	dividor = 1;
	while (nbr / dividor)
	{
		len++;
		dividor *= 10;
	}
	return (len);
}
