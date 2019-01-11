/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wordlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 08:46:02 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:35 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordlen(const char *string)
{
	int index;

	index = 0;
	while (string[index] && ft_isspace(string[index]) == 0)
		index++;
	return (index);
}
