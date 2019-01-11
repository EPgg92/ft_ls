/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 09:05:06 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:26 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		**clean_tab(char **tab, int size)
{
	while (size >= 0)
	{
		free(tab[size]);
		tab[size--] = NULL;
	}
	free(tab);
	return (NULL);
}

/*
** ft_strplit :
**
** Cut a given string with the specified charset
*/

char			**ft_strsplit(const char *str, const char *charset)
{
	char	**tab;
	int		tab_index;
	int		nb_elem;
	char	*delim;

	nb_elem = ft_count(str, charset);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_elem + 1))))
		return (NULL);
	tab_index = 0;
	while (nb_elem)
	{
		if (ft_incharset(*str, charset))
			str++;
		else
		{
			delim = ft_strpbrk(str, charset);
			if (!(tab[tab_index++] = delim ? ft_strsub(str, 0, delim - str) :\
						ft_strdup(str)))
				return (clean_tab(tab, tab_index - 1));
			nb_elem--;
			str = delim + 1;
		}
	}
	tab[tab_index] = NULL;
	return (tab);
}
