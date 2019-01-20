#include "ft_ls.h"
#include "utils.h"


/*
** Main test for parsing
**
** use :
** gcc sources/ls_parsing.c sources/test_parsing.c
** sources/utils_to_remove_debug/print_binary.c
** librairies/Libft/libft.a -Iincludes -Ilibrairies/Libft/ -g
*/

int main(int argc, char **argv)
{
	char **files_names;

	files_names = NULL;

	ft_printf("1FRSUalmortu\n");
	print_short(parse_argv_option(argc, argv, &files_names));
	while (*files_names)
		ft_printf("%s\n", *files_names++);
	return (0);
}
