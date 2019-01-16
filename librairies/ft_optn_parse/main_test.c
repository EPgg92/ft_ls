#include "includes/libopt.h"
#include <stdio.h>

static void	print_argv(int argc, char **argv)
{
	int index = 0;

	printf("argc : %d argv[0] = %s\n", argc, argv[0]);
	while (index < argc)
		ft_putendl(argv[index++]);
}

int	main(int argc, char **argv)
{
	t_head_optn *head;
	int pos_arg;

	head = (t_head_optn*)malloc(sizeof(t_head_optn));
	set_head_optn(&head);
	if (argc >= 2)
	{

		add_opt_head(&head, "-r", 0);
		add_opt_head(&head, "-l", 0);
		add_opt_head(&head, "-R", 0);
		add_opt_head(&head, "-1", 0);
		add_opt_head(&head, "-a", 0);
		add_opt_head(&head, "-F", 0);
		add_opt_head(&head, "-S", 0);
		add_opt_head(&head, "-u", 0);
		add_opt_head(&head, "-s", 0);
		add_opt_head(&head, "-m", 0);
		add_opt_head(&head, "-U", 0);
		add_opt_head(&head, "-o", 0);
		add_opt_head(&head, "-r", 0);
		add_opt_head(&head, "-A", 1);
		add_opt_head(&head, "--right", 1);
		update_head(&head);
		pos_arg = optparse(argc, argv, head);
		print_argv(head->argc, head->argv);
		printf("\n\nFinal list : \nFirst arg : %d\n", pos_arg);
		if (pos_arg != -1)
		{
			printf("FULL LIST : \n");
			print_optn_list(head->next);
		}
		if (head->next == NULL)
			printf("Arg_list is NULL \n");
	}
	return (0);
}
