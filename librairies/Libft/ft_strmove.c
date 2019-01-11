/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 07:05:54 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:14 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strmove :
**
** Remove the fisrt part of the string from a new given start.
** Fill the end with '\0'.
*/

void	ft_strmove(char *begin_str, char *new_begin)
{
	size_t	new_len;

	new_len = ft_strlen(new_begin);
	ft_memmove(begin_str, new_begin, new_len);
	ft_bzero(begin_str + new_len, new_begin - begin_str);
}
