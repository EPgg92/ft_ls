/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arraylen.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epoggio <epoggio@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 18:07:53 by epoggio      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 18:07:58 by epoggio     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int ft_arraylen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}