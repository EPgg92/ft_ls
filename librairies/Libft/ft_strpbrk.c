/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strpbrk.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 08:17:51 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:24 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *str, const char *charset)
{
	while (*str)
	{
		if (ft_incharset(*str, charset))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
