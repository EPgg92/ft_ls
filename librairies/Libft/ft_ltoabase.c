/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ltoabase.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 12:52:11 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:59:18 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digit(unsigned long long nbr, int base)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		count++;
		nbr /= base;
	}
	return (count);
}

char			*ft_ltoabase(unsigned long long nbr, const char *base)
{
	int		base_len;
	char	*itoa_str;
	int		nbr_char;

	if (nbr == 0)
		return (ft_strsub(base, 0, 1));
	base_len = ft_strlen(base);
	nbr_char = count_digit(nbr, base_len);
	if (!(itoa_str = (char *)malloc(sizeof(char) * (nbr_char + 1))))
		return (NULL);
	itoa_str[nbr_char--] = '\0';
	while (nbr)
	{
		itoa_str[nbr_char--] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (itoa_str);
}
