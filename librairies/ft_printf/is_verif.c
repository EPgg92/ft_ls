/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   is_verif.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:05:07 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 11:01:17 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int		is_specifier(int c)
{
	return (ft_incharset(c, "sSpdiouxXcCF%"));
}

int		is_flag(int c)
{
	return (ft_incharset(c, "0 #-+"));
}
