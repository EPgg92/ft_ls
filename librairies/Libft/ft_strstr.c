/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 10:59:27 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:27 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *full_str, const char *substring)
{
	int sublen;

	if (*substring == '\0')
		return ((char *)full_str);
	sublen = ft_strlen(substring);
	while (*full_str)
	{
		if (*full_str == *substring && !ft_strncmp(full_str, substring, sublen))
			return ((char *)full_str);
		full_str++;
	}
	return (NULL);
}
