/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_byteslen.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 16:04:31 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:04:39 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		str_byteslen(wchar_t *str)
{
	size_t	len;

	len = 0;
	while (*str)
		len += determine_bytes(*str++);
	return (len);
}
