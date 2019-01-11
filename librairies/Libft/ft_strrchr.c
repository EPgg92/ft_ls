/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 14:56:41 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:25 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *tmp;

	if (c == '\0')
		return ((char *)str + ft_strlen(str));
	tmp = NULL;
	while (*str)
	{
		if (*str == c)
			tmp = (char *)str;
		str++;
	}
	return (tmp);
}
