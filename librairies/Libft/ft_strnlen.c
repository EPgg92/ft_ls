/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 09:51:23 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:22 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(const char *str, size_t n)
{
	int index;

	index = 0;
	while (*(str + index) && n)
	{
		index++;
		n--;
	}
	return (index);
}
