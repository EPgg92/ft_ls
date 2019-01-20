/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   function_builder.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 16:18:26 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 18:16:58 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** free_manager:
**
** Called to free a t_fct_manager. Will also free his chained list.
*/

void			*free_manager(t_fct_manager **manager)
{
	free_fcts_list(&(*manager)->std_fcts);
	free_t_wfcts_list(&(*manager)->uni_fcts);
	free(*manager);
	*manager = NULL;
	return (NULL);
}

/*
** setup_unicode:
**
** Create and store into a t_wfcts chained list all specifier
** for unicode strings.
*/

static t_wfcts	*setup_unicode(void)
{
	t_wfcts	*functions_lst;
	int		error;

	error = 1;
	functions_lst = NULL;
	error *= push_unicode_elem(&functions_lst, "S", get_big_s);
	error *= push_unicode_elem(&functions_lst, "ls", get_big_s);
	error *= push_unicode_elem(&functions_lst, "C", get_big_c);
	error *= push_unicode_elem(&functions_lst, "lc", get_big_c);
	if (error == 0)
		free_t_wfcts_list(&functions_lst);
	return (functions_lst);
}

/*
** setup_base_functions:
**
** Create and push into a t_fcts list all of printf format to
** display number with base (x, X, o).
*/

static t_fcts	*setup_base_functions(void)
{
	int		error;
	t_fcts	*list_fct;

	list_fct = NULL;
	error = 1;
	error *= push_element(&list_fct, "llx", get_llbase);
	error *= push_element(&list_fct, "llX", get_llbase);
	error *= push_element(&list_fct, "lx", get_lbase);
	error *= push_element(&list_fct, "lX", get_lbase);
	error *= push_element(&list_fct, "x", get_base);
	error *= push_element(&list_fct, "X", get_base);
	error *= push_element(&list_fct, "hx", get_h_hhbase);
	error *= push_element(&list_fct, "hX", get_h_hhbase);
	error *= push_element(&list_fct, "hhX", get_h_hhbase);
	error *= push_element(&list_fct, "hhx", get_h_hhbase);
	error *= push_element(&list_fct, "llo", get_llbase);
	error *= push_element(&list_fct, "lo", get_llbase);
	error *= push_element(&list_fct, "o", get_base);
	error *= push_element(&list_fct, "ho", get_h_hhbase);
	error *= push_element(&list_fct, "hho", get_h_hhbase);
	if (!error)
		free_fcts_list(&list_fct);
	return (list_fct);
}

/*
** setup_standard:
**
** Will fill all specifier who won't be unicode specifier.
** Will call setup_base_functions and add more node
** into t_fcts list.
*/

static t_fcts	*setup_standard(void)
{
	t_fcts	*list_fct;
	int		error;

	if (!(list_fct = setup_base_functions()))
		return (NULL);
	error = 1;
	error *= push_element(&list_fct, "llu", get_llu);
	error *= push_element(&list_fct, "llu", get_llu);
	error *= push_element(&list_fct, "lu", get_lu);
	error *= push_element(&list_fct, "u", get_u);
	error *= push_element(&list_fct, "hu", get_h_hhu);
	error *= push_element(&list_fct, "hhu", get_h_hhu);
	error *= push_element(&list_fct, "lld", get_lld);
	error *= push_element(&list_fct, "ld", get_ld);
	error *= push_element(&list_fct, "d", get_d);
	error *= push_element(&list_fct, "hd", get_h_hhd);
	error *= push_element(&list_fct, "hhd", get_h_hhd);
	error *= push_element(&list_fct, "p", get_p);
	error *= push_element(&list_fct, "c", get_c);
	error *= push_element(&list_fct, "%", get_percent);
	error *= push_element(&list_fct, "s", get_s);
	error *= push_element(&list_fct, "r", get_r);
	error *= push_element(&list_fct, "F", get_big_f);
	if (!error)
		free_fcts_list(&list_fct);
	return (list_fct);
}

/*
** setup_functions:
**
** Call all of our setup function who will fill t_fcts or t_wfcts chained list.
** Create a t_fct_manager to store both list in the same structure.
*/

t_fct_manager	*setup_functions(void)
{
	t_fct_manager	*manager;

	if (!(manager = (t_fct_manager *)malloc(sizeof(t_fct_manager))))
		return (NULL);
	manager->std_fcts = setup_standard();
	manager->uni_fcts = setup_unicode();
	if (!manager->uni_fcts || !manager->std_fcts)
		return (free_manager(&manager));
	return (manager);
}
