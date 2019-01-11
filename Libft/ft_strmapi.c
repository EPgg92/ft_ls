/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 10:57:17 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:13 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*fct)(unsigned int, char))
{
	int		index;
	char	*map_str;

	index = 0;
	if (!(map_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (map_str);
	while (str[index])
	{
		map_str[index] = fct(index, str[index]);
		index++;
	}
	map_str[index] = '\0';
	return (map_str);
}
