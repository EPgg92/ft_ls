/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 07:05:54 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 15:01:12 by simrossi    ###    #+. /#+    ###.fr     */
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

void	ft_strmove(char *old_start, char *new_begin)
{
	size_t	new_len;

	new_len = ft_strlen(new_begin);
	ft_memmove(old_start, new_begin, new_len);
	ft_bzero(old_start + new_len, new_begin - begin_str);
}
