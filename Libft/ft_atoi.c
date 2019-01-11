/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 08:31:06 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:58:47 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *string)
{
	int		negative;
	int		result;

	result = 0;
	negative = 0;
	while (ft_isspace(*string))
		string++;
	if (*string == '-')
	{
		negative = 1;
		string++;
	}
	else if (*string == '+')
		string++;
	while (*string >= '0' && *string <= '9')
		result = result * 10 + *string++ - '0';
	return (negative ? -result : result);
}
