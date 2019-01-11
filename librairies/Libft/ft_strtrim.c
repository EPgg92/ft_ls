/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 15:35:27 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:30 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_not_space(int c)
{
	return (ft_isspace(c) == 0 ? 1 : 0);
}

char			*ft_strtrim(char const *str)
{
	char *start;
	char *end;

	start = ft_fstrchr(str, ft_not_space);
	end = ft_fstrrchr(str, ft_not_space);
	return (ft_strsub(start ? start : "", 0, end - start + 1));
}
