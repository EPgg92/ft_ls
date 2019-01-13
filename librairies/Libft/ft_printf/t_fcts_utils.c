/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   t_fcts_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:10:24 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 09:59:52 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** node_create:
**
** Allocate and return a t_fcts * structure. Fill
** his attribute.
*/

static t_fcts	*node_create(char *key, t_build_fct format_fct)
{
	t_fcts *node;

	if (!(node = (t_fcts *)malloc(sizeof(t_fcts))))
		return (NULL);
	node->key = key;
	node->string_maker = format_fct;
	node->next = NULL;
	return (node);
}

/*
** free_t_fcts:
**
** free a single t_fcts * structure.
*/

static void		*free_t_fcts_node(t_fcts **node)
{
	free(*node);
	*node = NULL;
	return (NULL);
}

/*
** free_fcts_list:
**
** Free the entire chained list of t_fcts.
*/

void			*free_fcts_list(t_fcts **list)
{
	t_fcts *tmp_next;
	t_fcts *tmp_curr;

	tmp_curr = *list;
	while (tmp_curr)
	{
		tmp_next = tmp_curr->next;
		free_t_fcts_node(&tmp_curr);
		tmp_curr = tmp_next;
	}
	*list = NULL;
	return (NULL);
}

/*
** push_element:
**
** Add a new element into the given t_fcts chained list.
*/

int				push_element(t_fcts **list_fct, char *key, \
							t_build_fct format_fct)
{
	t_fcts	*tmp;

	if (!*list_fct)
	{
		*list_fct = node_create(key, format_fct);
		return (*list_fct ? 1 : 0);
	}
	tmp = *list_fct;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node_create(key, format_fct);
	return (tmp->next ? 1 : 0);
}
