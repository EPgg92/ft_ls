
#include "libopt.h"

/*
** get_optn:
**
** Acces to a *t_optn element from the option's raw string.
** Return NULL if reserach failed, a *t_optn element otherwise.
*/

t_optn	*get_optn(t_optn *optn_list, const char *name)
{
	while (optn_list)
	{
		if (ft_strncmp(name, optn_list->name, ft_strlen(name) == 0))
			return (optn_list);
		optn_list = optn_list->next;
	}
	return (NULL);
}
