/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putuchar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 16:13:24 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:13:25 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_putuchar(unsigned char c)
{
	wchar_t print_value;

	print_value = c;
	return (ft_putwchar(print_value));
}
