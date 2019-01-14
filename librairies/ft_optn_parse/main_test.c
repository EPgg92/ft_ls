#include "libopt.h"
#include <stdio.h>

// static void	print_argv(int argc, char **argv)
// {
// 	int index = 0;
//
// 	printf("argc : %d argv[0] = %s\n", argc, argv[0]);
// 	while (index < argc)
// 		ft_putendl(argv[index++]);
// }

int 	ft_printf(char *format, ...);

int	main(int argc, char **argv)
{
	//t_optn *arg_list;
	t_head_optn *head;
	int pos_arg;

	//arg_list = NULL;
	head = (t_head_optn*)malloc(sizeof(t_head_optn));
	set_head_optn(&head);

	//if (argc >= 2)
	//{
		//push_back_optn(&arg_list, "-l", 0);
		add_opt_head(&head, "-l", 0);
		add_opt_head(&head, "-r", 0);
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
		//add_opt_head(&head, "-z", 1);
		//add_opt_head(&head, "-A", 1);
		//add_opt_head(&head, "--right", 1);
		//add_opt_head(&head, "--center", 1);
		//add_opt_head(&head, "--left", 1);
		update_head(&head);
		ft_printf("%s\n", head->opt_sing);
		ft_printf("%s\n", head->opt_arg);
		int i = 0;
		while(head->opt_long[i])
		 	ft_printf("-> %s\n", head->opt_long[i++]);
		pos_arg = (int)argv[--argc];
		clear_head_optn(&head);
		//printf("%s\n", "LOL" );
		// update
		pos_arg = optparse(argc, argv, &head->next);
		// print_argv(argc, argv);
		// printf("\n\nFinal list : \nFirst arg : %d\n", pos_arg);
		// if (pos_arg != -1)
		// {
		// 	printf("FULL LIST : \n");
		// 	print_optn_list(arg_list);
		// }
		// if (arg_list == NULL)
		// 	printf("Arg_list is NULL \n");
	//}
	return (0);
}



// int	main(int argc, char **argv)
// {
// 	t_optn *arg_list;
// 	int pos_arg;
//
// 	arg_list = NULL;
// 	if (argc >= 2)
// 	{
// 		push_front_optn(&arg_list, "--len", 1);
// 		printf("arg_list  : %p   next : %p\n", arg_list, arg_list->next);
// 		add_opt_head(&head, "-R", 1);
// 		add_opt_head(&head, "--speed", 1);
// 		push_front_optn(&arg_list, "--size", 1);
// 		push_front_optn(&arg_list, "-l", 0);
// 		push_front_optn(&arg_list, "-v", 1);
// 		add_opt_head(&head, "-j", 0);
// 		pos_arg = optparse(argc, argv, &arg_list);
// 		print_argv(argc, argv);
// 		printf("\n\n Final list : \nFirst arg : %d\n", pos_arg);
// 		if (pos_arg != -1)
// 		{
// 			printf("FULL LIST : \n");
// 			print_optn_list(arg_list);
// 		}
// 		if (arg_list == NULL)
// 			printf("Arg_list is NULL \n");
// 	}
// 	return (0);
// }
