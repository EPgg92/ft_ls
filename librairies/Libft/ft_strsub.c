/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 08:26:17 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:27 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substring;

	if (!(substring = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(substring, s + start, len);
	substring[len] = '\0';
	return (substring);
}
