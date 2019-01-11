/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 10:14:10 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:10 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Merci Alex
*/

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_src;
	size_t len_dst;
	size_t index;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	index = len_dst;
	if (size <= len_dst)
		return (size + len_src);
	while (index < size - 1)
		dst[index++] = *src++;
	dst[index] = '\0';
	return (len_src + len_dst);
}
