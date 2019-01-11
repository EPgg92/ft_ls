/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 10:27:17 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:59:35 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_putnbr_fd(int nb, int fd)
{
	int printed;

	printed = 0;
	if (nb < 0)
	{
		printed += ft_putchar_fd('-', fd);
		if (nb == -2147483648)
		{
			printed += ft_putchar_fd('2', fd);
			nb += 2000000000;
		}
		printed += ft_putnbr_fd(nb * -1, fd);
	}
	else if (nb >= 10)
	{
		printed += ft_putnbr_fd(nb / 10, fd);
		printed += ft_putchar_fd(nb % 10 + '0', fd);
	}
	else if (nb <= 9)
		printed += ft_putchar_fd(nb + '0', fd);
	return (printed);
}
