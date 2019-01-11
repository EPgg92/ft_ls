/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_optn.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 11:37:15 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 11:37:22 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libopt.h"

void	print_optn_list(t_optn *arg_list)
{
	while (arg_list)
	{
		printf("Arg : %s\n", arg_list->name);
		printf("option name : %s  | Expect args : %d ", arg_list->name,
				arg_list->expect_arg);
		if (arg_list->arg != NULL)
			printf("  | args : %s", arg_list->arg);
		ft_putchar('\n');
		printf("active : %d\n", arg_list->active);
		if (arg_list->next)
			ft_putchar('\n');
		arg_list = arg_list->next;
	}
	if (arg_list == NULL)
		printf("END IS NULL\n");
}

void	print_chained(t_optn *optn_list)
{
	while (optn_list)
	{
		printf("%s>>", optn_list->name);
		optn_list = optn_list->next;
	}
	printf("NULL\n");
}

void	print_optn_node(t_optn *arg_node)
{
	if (!arg_node)
		return ;
	printf("option name : %s  | Expect args : %d\n", arg_node->name,
			arg_node->expect_arg);
	printf("active : %d", arg_node->active);
	if (arg_node->arg != NULL)
		printf("  | args : %s\n", arg_node->arg);
	else
		ft_putchar('\n');
}
