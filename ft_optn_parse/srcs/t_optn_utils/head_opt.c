#include "../../includes/libopt.h"

int clear_head_optn(t_head_optn **head)
{
	t_head_optn *this;

		this = *head;
	if (this->next != NULL)
	{
		char **opt_long;
		int i;

		i = 0;
		opt_long = this->opt_long;
		clear_optn_list(&(this->next));
		(this->opt_arg) ? ft_strdel(&this->opt_arg) : 0;
		(this->opt_sing) ? ft_strdel(&this->opt_sing) : 0;
		if (opt_long)
		{
			while (opt_long[i] != NULL)
				ft_strdel(&opt_long[i++]);
			ft_memdel((void **)opt_long);
		}
	}
	return(0);
}

int set_head_optn(t_head_optn **head)
{
	t_head_optn *this;

	this = *head;
	this->next = NULL;
	this->opt_arg = "\0";
	this->opt_sing = "\0";
	this->opt_long = NULL;
	this->opt_arg = 0;
	this->nb_opt_sing = 0;
	this->nb_opt_long = 0;
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
	h->opt_sing = ft_strnew(13); //13 <- h->nb_opt_sing
	h->opt_arg = ft_strnew(2); // 2 <- h->nb_opt_sing
	h->opt_long = (char **)malloc(sizeof(char *) * 3); // 3 <- h->nb_opt_long
	if (!h->opt_long || !h->opt_sing || !h->opt_arg)
		return (clear_head_optn(head));
	tab =  h->opt_long;
	while(l != NULL)
	{
		if (ft_strnlen(l->name, 3) == 2)
			l->expect_arg ? add_char(h->opt_arg, l->name[1]) : \
				add_char(h->opt_sing, l->name[1]);
		else
			*tab++ = ft_strdup(l->name);
		l = l->next;
	}
	*(h->opt_long) = NULL;
	return(1);
}
