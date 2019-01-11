/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrdup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 16:05:22 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:05:43 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrdup(wchar_t *wstr)
{
	wchar_t	*duplicate;
	int		len;

	len = ft_wstrlen(wstr);
	if (!(duplicate = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1))))
		return (NULL);
	ft_wstrcpy(duplicate, wstr);
	return (duplicate);
}
