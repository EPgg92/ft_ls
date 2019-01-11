/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memcmp.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 16:35:59 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:59:21 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *tmp_src;

	tmp_src = (unsigned char *)src;
	while (n)
	{
		if (*tmp_src == (unsigned char)c)
			return ((void *)tmp_src);
		tmp_src++;
		n--;
	}
	return (NULL);
}
