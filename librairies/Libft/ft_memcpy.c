/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 11:45:17 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:59:23 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dst_tmp;
	char *src_tmp;

	dst_tmp = (char *)dst;
	src_tmp = (char *)src;
	while (n)
	{
		*dst_tmp++ = *src_tmp++;
		n--;
	}
	return (dst);
}
