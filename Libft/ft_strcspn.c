/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcspn.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/27 15:39:24 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:59:59 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strcspn(const char *s, const char *charset)
{
	size_t	index;
	char	ptr;

	index = 0;
	while (*s && (ptr = ft_strchr(charset, *s++) == NULL))
		index++;
	return (index);
}
