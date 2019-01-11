/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fstrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 09:58:00 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:58:59 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrchr(const char *str, int (*fct)(int))
{
	while (*str)
	{
		if (fct(*str))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
