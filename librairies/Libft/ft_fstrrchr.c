/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fstrrchr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 10:02:26 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:59:01 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrrchr(const char *str, int (*fct)(int))
{
	int index;

	index = ft_strlen(str) - 1;
	while (index >= 0)
	{
		if (fct(str[index]))
			return ((char *)str + index);
		index--;
	}
	return (NULL);
}
