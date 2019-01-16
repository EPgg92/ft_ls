
#include "libopt.h"

t_optn	*create_optn(const char *name, int expect_arg)
{
	t_optn *optn;

	if (!(optn = (t_optn *)malloc(sizeof(*optn))))
		return (NULL);
	optn->name = name;
	optn->expect_arg = expect_arg;
	optn->active = 0;
	optn->arg = NULL;
	optn->next = NULL;
	return (optn);
}

int	push_back_optn(t_optn **optn_list, const char *name, int expect_arg)
{
	t_optn *optn_tmp;

	optn_tmp = *optn_list;
	if (optn_tmp == NULL)
	{
		*optn_list = create_optn(name, expect_arg);
		return (*optn_list != NULL);
	}
	while (optn_tmp->next)
		optn_tmp = optn_tmp->next;
	optn_tmp->next = create_optn(name, expect_arg);
	return (optn_tmp->next != NULL);

}

int	push_front_optn(t_optn **optn_list, const char *name, int expect_arg)
{
	t_optn *optn_tmp;

	if (!*optn_list)
	{
		*optn_list = create_optn(name, expect_arg);
		return (*optn_list != NULL);
	}
	optn_tmp = create_optn(name, expect_arg);
	optn_tmp->next = *optn_list;
	*optn_list = optn_tmp;
	return (optn_tmp->next != NULL);
}

void		deplace_active(t_optn **options_list, t_optn *deplaced_node)
{
	t_optn *curr;
	t_optn *prev;

	curr = *options_list;
	prev = NULL;
	while (curr && curr->active)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev)
	{
		prev->next = deplaced_node;
		deplaced_node->next = curr;
	}
	else
	{
		*options_list = deplaced_node;
		deplaced_node->next = curr;
	}
}

int			deplace_option(t_optn **begin, t_optn *node)
{
	t_optn *curr;
	t_optn *prev;
	t_optn *tmp;

	prev = NULL;
	tmp = NULL;
	curr = *begin;
	while (curr)
	{
		if (curr == node)
		{
			tmp = curr;
			if (!prev)
				*begin = curr->next;
			else
				prev->next = curr->next;
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
	deplace_active(begin, tmp);
	return (0);
}
