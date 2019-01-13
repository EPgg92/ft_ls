
#include "libopt.h"

/*
** clear_optn_list:
**
** Free an entire t_optn list.
*/

int		clear_optn_list(t_optn **optn_list)
{
	t_optn *buf_next;

	if (!*optn_list)
		return (1);
	buf_next = (*optn_list)->next;
	while ((*optn_list))
	{
		free(*optn_list);
		*optn_list = NULL;
		if (buf_next)
		{
			(*optn_list) = buf_next;
			buf_next = buf_next->next;
		}
	}
	return (1);
}

/*
** remove_unactive:
**
** Clean an t_optn array, remove option with an active flag set to 0.
*/

void	remove_unactive(t_optn **optn_list)
{
	while (*optn_list && (*optn_list)->active)
		optn_list = &(*optn_list)->next;
	clear_optn_list(optn_list);
}
