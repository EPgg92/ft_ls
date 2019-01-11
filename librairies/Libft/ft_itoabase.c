/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoabase.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 11:58:37 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:15:20 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digit(unsigned int nbr, int base)
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

char			*ft_itoabase(unsigned int nbr, const char *base)
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

static size_t	count_lldigit(unsigned long long int nbr, int base)
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

char			*ft_lltoabase(unsigned long long int nbr, const char *base)
{
	int		base_len;
	char	*itoa_str;
	int		nbr_char;

	if (nbr == 0)
		return (ft_strsub(base, 0, 1));
	base_len = ft_strlen(base);
	nbr_char = count_lldigit(nbr, base_len);
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
