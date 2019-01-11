/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 15:10:56 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:23 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *full_str, const char *substring, size_t len)
{
	char	*last_char;
	int		len_substring;

	if (*substring == '\0')
		return ((char *)full_str);
	len_substring = ft_strlen(substring);
	last_char = (char *)full_str + len;
	while (*full_str && last_char - full_str >= len_substring)
	{
		if (*full_str == *substring && \
				ft_strncmp(full_str, substring, len_substring) == 0)
			return ((char *)full_str);
		full_str++;
	}
	return (NULL);
}
