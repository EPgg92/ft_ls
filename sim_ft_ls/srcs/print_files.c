#include "ft_ls.h"

void	print_tab(t_file **file_list);

t_file	**stack_extend(t_file **curr_stack, t_file *extra)
{
	int index;
	t_file **extend;

	index = 0;
	while (curr_stack[index])
		index++;
	extend = (t_file **)malloc(sizeof(t_file *) * (index + 2));
	index = 0;
	while (curr_stack[index])
	{
		extend[index] = curr_stack[index];
		index++;
	}
	extend[index++] = extra;
	extend[index] = NULL;
	free(curr_stack);
	return (extend);
}

void	fold_stack(t_file ***wait_list, t_file *new_fold)
{
	t_file **new_stack;

	if (!*wait_list)
	{
		new_stack = (t_file **)malloc(sizeof(t_file *) * 2);
		*new_stack = new_fold;
		*(new_stack + 1) = NULL;
		*wait_list = new_stack;
	}
	else
		*wait_list = stack_extend(*wait_list, new_fold);
}


void	print_tab(t_file **file_list)
{
	int index;

	index = 0;
	PRT("File list : ");
	while (*(file_list + index))
	{
		PRT("%d ", index);
		PRT("%s --> ", file_list[index]->name);
		index++;
	}
	PRT("\n");
}


void	tree_print(t_file *file_list)
{
	print_file_chained(file_list);
	ft_putchar('\n');
	while (file_list)
	{
		if (file_list->fold_child)
			tree_print(file_list->fold_child);
		file_list = file_list->next;
	}
			
}

void	folder_print(const char *fold, t_file *file_list, t_optn_var *optns)
{
	t_file **file_stack;
	int index;
	
	file_stack = NULL;
	if (optns->recursive)
		PRT("%s :\n", fold);
	while (file_list)
	{
		PRT("%s  ", file_list->name);
		if (optns->recursive && file_list->fold_child)
			fold_stack(&file_stack, file_list);
		file_list = file_list->next;
	}
	PRT("\n");
	if (optns->recursive && file_stack)
	{
		index = -1;
		PRT("\n");
		while (file_stack[++index])
		{
			folder_print(file_stack[index]->abs_path, file_stack[index]->fold_child, optns);
			if (file_stack[index + 1])
				PRT("\n");
		}
	}
}
