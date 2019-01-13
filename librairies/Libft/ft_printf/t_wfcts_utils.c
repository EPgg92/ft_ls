/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   t_wfcts_utils.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:08:41 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 10:14:08 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void		*free_t_wfcts_element(t_wfcts **node)
{
	free(*node);
	*node = NULL;
	return (NULL);
}

void			*free_t_wfcts_list(t_wfcts **unicode_list)
{
	t_wfcts *tmp;
	t_wfcts *next;

	tmp = *unicode_list;
	while (tmp)
	{
		next = tmp->next;
		free_t_wfcts_element(&tmp);
		tmp = next;
	}
	*unicode_list = NULL;
	return (NULL);
}

static t_wfcts	*create_node(char *key, t_unicode_fct format_function)
{
	t_wfcts *node;

	if (!(node = (t_wfcts *)malloc(sizeof(t_wfcts))))
		return (NULL);
	node->next = NULL;
	node->key = key;
	node->string_maker = format_function;
	return (node);
}

int				push_unicode_elem(t_wfcts **unicode_lst, char *key, \
		t_unicode_fct fct)
{
	t_wfcts *tmp;

	if (!*unicode_lst)
	{
		*unicode_lst = create_node(key, fct);
		return (*unicode_lst ? 1 : 0);
	}
	tmp = *unicode_lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_node(key, fct);
	return (tmp->next ? 1 : 0);
}
