#include "../../includes/libopt.h"

int clear_head_optn(t_head_optn **head)
{
	t_head_optn *this;

		this = *head;
	if (this->next != NULL)
	{
		char **opt_long;
		int i;

		i = -1;
		opt_long = this->opt_long;
		clear_optn_list(&(this->next));
		(this->opt_arg) ? ft_strdel(&this->opt_arg) : 0;
		(this->opt_sing) ? ft_strdel(&this->opt_sing) : 0;
		if (this->nb_opt_long != 0)
		{
			while (++i < this->nb_opt_long)
				ft_strdel(&opt_long[i]);
			free(opt_long);
		}
	}
	ft_memdel((void **)head);
	return(0);
}

int set_head_optn(t_head_optn **head)
{
	t_head_optn *this;

	this = *head;
	this->next = NULL;
	this->opt_arg = NULL;
	this->opt_sing = NULL;
	this->opt_long = NULL;
	this->nb_opt_arg = 2;
	this->nb_opt_sing = 13;
	this->nb_opt_long = 3;
	return (0);
}

static void add_char(char *str, char c)
{
	while(*str)
		str++;
	*str = c;
}

int update_head(t_head_optn **head)
{
	t_head_optn	*h;
	t_optn		*l;
	char		**tab;

	h = *head;
	l = h->next;
	h->opt_sing = ft_strnew(h->nb_opt_sing);
	h->opt_arg = ft_strnew(h->nb_opt_arg);
	h->opt_long = (char **)malloc(sizeof(char *) * (h->nb_opt_long + 1));
	if (!h->opt_long || !h->opt_sing || !h->opt_arg)
		return (clear_head_optn(head));
	tab =  h->opt_long;
	while(l != NULL)
	{
		if (ft_strnlen(l->name, 3) == 2)
			l->expect_arg ? add_char(h->opt_arg, l->name[1]) : \
				add_char(h->opt_sing, l->name[1]);
		else
			*tab++ = ft_strdup(l->name + 2);
		l = l->next;
	}
	*tab = NULL;
	return(1);
}


int add_opt_head(t_head_optn **head, char *name_opt, unsigned int opt_arr)
{
	t_head_optn *h;

	h = *head;
	if (ft_strnlen(name_opt, 3) == 2)
		opt_arr ? h->nb_opt_arg++ : h->nb_opt_sing++;
	else
		h->nb_opt_long++;
	push_back_optn(&h->next, name_opt, opt_arr);
	return (0); // TODO retombé d'erreurs dans push_back_optn & create_node
}
