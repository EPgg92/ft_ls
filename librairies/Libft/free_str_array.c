/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_str_array.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epoggio <epoggio@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 16:46:16 by epoggio      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 18:31:29 by epoggio     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

void		free_str_array(char ***str)
{
	int index;

	index = 0;
	while ((*str)[index])
		free((*str)[index++]);
	free(*str);
	*str = NULL;
}
