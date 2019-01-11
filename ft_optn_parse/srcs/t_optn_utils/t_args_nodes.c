
#include "libopt.h"

t_optn	*create_optn(const char *name, int expect_arg)
{
	t_optn *optn;

	if (!(optn = (t_optn *)malloc(sizeof(t_optn))))
		return (NULL);
	optn->name = name;
	optn->expect_arg = expect_arg;
	optn->active = 0;
	optn->arg = NULL;
	optn->next = NULL;
	return (optn);
}

void	push_back_optn(t_optn **optn_list, const char *name, int expect_arg)
{
	t_optn *optn_tmp;

	optn_tmp = *optn_list;
	if (optn_tmp == NULL)
	{
		*optn_list = create_optn(name, expect_arg);
		return ;
	}
	while (optn_tmp->next)
		optn_tmp = optn_tmp->next;
	optn_tmp->next = create_optn(name, expect_arg);
}

void	push_front_optn(t_optn **optn_list, const char *name, int expect_arg)
{
	t_optn *optn_tmp;

	if (!*optn_list)
	{
		*optn_list = create_optn(name, expect_arg);
		return ;
	}
	optn_tmp = create_optn(name, expect_arg);
	optn_tmp->next = *optn_list;
	*optn_list = optn_tmp;
}
