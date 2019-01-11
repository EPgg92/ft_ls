/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 08:19:30 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:18 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int index;

	index = 0;
	while (n && *src)
	{
		*(dest + index++) = *(src++);
		n--;
	}
	while (n)
	{
		*(dest + index++) = '\0';
		n--;
	}
	return (dest);
}
