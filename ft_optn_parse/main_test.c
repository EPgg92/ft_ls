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
	t_optn *arg_list;
	t_head_optn *head;
	int pos_arg;

	arg_list = NULL;
	head = (t_head_optn*)malloc(sizeof(t_head_optn));
	set_head_optn(&head);

	//if (argc >= 2)
	//{
		push_back_optn(&arg_list, "-l", 0);
		head->next = arg_list;
		push_back_optn(&arg_list, "-r", 0);
		push_back_optn(&arg_list, "-R", 0);
		push_back_optn(&arg_list, "-z", 1);
		push_back_optn(&arg_list, "-1", 0);
		push_back_optn(&arg_list, "-a", 0);
		push_back_optn(&arg_list, "-F", 0);

		push_back_optn(&arg_list, "-S", 0);
		push_back_optn(&arg_list, "-u", 0);
		push_back_optn(&arg_list, "-s", 0);
		push_back_optn(&arg_list, "-m", 0);
		push_back_optn(&arg_list, "-U", 0);
		push_back_optn(&arg_list, "-o", 0);
		//push_back_optn(&arg_list, "-r", 0);
		push_back_optn(&arg_list, "-A", 1);
		push_back_optn(&arg_list, "--right", 1);
		push_back_optn(&arg_list, "--left", 1);
		update_head(&head);
		ft_printf( "%s\n", head->opt_sing);
		ft_printf("%s\n", head->opt_arg);
		// printf("%s\n", head->opt_arg);
		// printf("%s\n", head->opt_sing);
		// printf("%s\n",head->opt_long[1] );
		// //while(*head->opt_long)
			//printf("%s\n", *head->opt_long++);
		pos_arg = (int)argv[--argc];
		clear_head_optn(&head);
		//printf("%s\n", "LOL" );
		// update
		// pos_arg = optparse(argc, argv, &arg_list);
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
// 		push_back_optn(&arg_list, "-R", 1);
// 		push_back_optn(&arg_list, "--speed", 1);
// 		push_front_optn(&arg_list, "--size", 1);
// 		push_front_optn(&arg_list, "-l", 0);
// 		push_front_optn(&arg_list, "-v", 1);
// 		push_back_optn(&arg_list, "-j", 0);
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
