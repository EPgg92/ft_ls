/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_str_array.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epoggio <epoggio@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 16:46:16 by epoggio      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 18:13:20 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int			free_str_array(char ***str, int status)
{
	int index;

	index = 0;
	while ((*str)[index])
		free((*str)[index++]);
	free(*str);
	*str = NULL;
	return (status);
}
