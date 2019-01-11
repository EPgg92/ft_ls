/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_istrcmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 08:36:19 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:59:14 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_istrcmp(const char *s1, const char *s2)
{
	int index;

	index = 0;
	while (s1[index] && s2[index] && \
			ft_tolower(s1[index]) == ft_tolower(s2[index]))
		index++;
	return (!s1[index] && !s2[index] ? 1 : 0);
}
