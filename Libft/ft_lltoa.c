/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lltoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 16:16:18 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:17:01 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char		*ft_lltoa(long long int nbr)
{
	int		len;
	char	*nbr_string;
	int		negativ;

	len = ft_nbrlen(nbr);
	negativ = nbr < 0 ? 1 : 0;
	if (!(nbr_string = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nbr_string[len--] = '\0';
	while (len >= 0)
	{
		nbr_string[len--] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
	}
	if (negativ)
		nbr_string[0] = '-';
	return (nbr_string);
}

char		*ft_llutoa(unsigned long long int nbr)
{
	int		len;
	char	*nbr_string;

	len = ft_unbrlen(nbr);
	if (!(nbr_string = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nbr_string[len--] = '\0';
	while (len >= 0)
	{
		nbr_string[len--] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
	}
	return (nbr_string);
}
