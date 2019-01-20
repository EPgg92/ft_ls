/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 18:12:51 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 18:12:52 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *str)
{
	int		len;
	char	*rev;

	len = ft_strlen(str);
	rev = ft_strnew(len);
	while (len)
		rev[--len] = *str++;
	return (rev);
}
