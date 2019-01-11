/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 14:40:21 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:14:40 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;
	int					diff;

	diff = dst - src;
	tmp_dst = diff > 0 ? (unsigned char *)dst + len - 1 : (unsigned char *)dst;
	tmp_src = diff > 0 ? (const unsigned char *)src + len - 1 : \
						(const unsigned char *)src;
	while (len)
	{
		if (diff > 0)
			*tmp_dst-- = *tmp_src--;
		else
			*tmp_dst++ = *tmp_src++;
		len--;
	}
	return (dst);
}
