/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wordcount.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 08:54:35 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:34 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(const char *str)
{
	int in_word;
	int word_count;

	word_count = 0;
	in_word = 0;
	while (*str)
	{
		if (ft_isspace(*str) == 0 && in_word == 0)
		{
			in_word = 1;
			word_count++;
		}
		else if (ft_isspace(*str) && in_word == 1)
			in_word = 0;
		str++;
	}
	return (word_count);
}
