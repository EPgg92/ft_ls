/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 08:38:26 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:09 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		entire_len;
	char	*joined_str;
	int		first_str_len;

	first_str_len = ft_strlen(s1);
	entire_len = first_str_len + ft_strlen(s2);
	if (!(joined_str = (char *)malloc(sizeof(char) * entire_len + 1)))
		return (NULL);
	ft_strncpy(joined_str, s1, first_str_len);
	ft_strcpy(joined_str + first_str_len, s2);
	return (joined_str);
}
