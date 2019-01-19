#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "libft.h"
#include "include/ft_ls.h"

#define ALL_OPT "utromlaUSRF1"
				//1FRSUalmortu
#define RESET_SORT 0b000110000001
#define RESET_PRINT 0b100000111000

#define U_MIN 0b1
#define T_MIN 0b10
#define R_MIN 0b100
#define O_MIN 0b1000
#define M_MIN 0b10000
#define L_MIN 0b100000
#define A_MIN 0b1000000
#define U_MAJ 0b10000000
#define S_MAJ 0b100000000
#define R_MAJ 0b1000000000
#define F_MAJ 0b10000000000
#define OPT_1 0b100000000000

int is_valid_opt(char *str)
{
	int i;

	i = 0;
	if (str[i++] == '-' && ft_strnlen(str, 2) > 1)
	{
		while (str[i])
		{
			if (!ft_strchr(ALL_OPT, str[i]))
				return(i); // str[i] is not a valid option
			i++;
		}
		return (0); // all valid option
	}
	return (-1); // not an option
}

void print_binary(long nb , int iter)
{
	if (iter)
		print_binary(nb>>1 ,--iter);
	printf("%d", nb % 2 != 0);
}

void print_short(short to_print)
{
	print_binary((long)to_print, 11);
	printf("\n");
}

int find_index(char* str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
	 	if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

short set_active_opt(short opt, char first)
{
	short tmp;
	int span;

	if (first != 'o')
	{
		tmp = 1;
		span = find_index(ALL_OPT, first); // je crois que l'on peu utiliser strspn ...
		tmp <<= span;
	}
	else
		tmp = L_MIN | O_MIN; // speciation of l with o
	if (first == '1' || first == 'm' || first == 'l' || first == 'o') // reset priority printing
		opt = opt & ~RESET_PRINT;
	else if (first == 'u' || first == 'U' || first == 'S') // reset priority sort
		opt = opt & ~RESET_SORT;
	return (tmp | opt);
}

short set_active_multi_opt(short opt, char *opt_name)
{
	int i;
	i = 1;

	while(opt_name[i])
		opt = set_active_opt(opt, opt_name[i++]);
	return (opt);
}

char **create_tab(int size)
{
	int i;
	char **tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (++size))))
		return (NULL);
	i = 0;
	while (i < size)
		tab[i++] = NULL;
	return (tab);
}






t_file *create_tfile(char *path)
{
	t_file *node

	if (!(node = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	node->path = NULL;
	node->pw_name = NULL;
	node->gr_name = NULL;
	node->modification_time = NULL;
	node->symbolic_link = NULL;
	node->next = NULL;
	if (!(node->info = (struct stat*)malloc(sizeof(struct stat))))
		return (freeaNULL);
	if (!(node->path = ft_strdup(path)))
		return (freeaNULL);
	return (node);
}


int test_readdir(char *name_dir)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(name_dir);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
            printf("%s\n", dir->d_name);
        closedir(d);
    }
    return(0);
}


int main(int argc, char **argv)
{
	short	active_opt;
	int		invalid_opt;
	char	**files_names;
	int		i;

	active_opt = 0;
	i = 0;
	if (!(files_names = create_tab(argc)))
		return (-1);
	while (*++argv)
	{
		if (!ft_strncmp(*argv, "--", 3))
		{
			argv++;
			break ;
		}
		else if((invalid_opt = is_valid_opt(*argv)) >= 0)
		{
			if (invalid_opt != 0)
				break ;
			active_opt = set_active_multi_opt(active_opt, *argv);
		}
		else
			files_names[i++] = ft_strdup(*argv);

	}
	while (*argv && invalid_opt == 0)
		files_names[i++] = ft_strdup(*argv++);
	if (files_names[0] == NULL)
		files_names[0] = ft_strdup(".");

	// to rm ...
	if (invalid_opt > 0)
		printf("Invalid option %s %d\n", *argv , invalid_opt);
	printf("Les options actives:\n");
	printf("%s\n", "1FRSUalmortu");
	print_short(active_opt);
	printf("Fichiers/dossiers à lister:\n");
	i = 0;
	while (files_names[i])
		printf("%s\n", files_names[i++]);
	// stop
	printf("######################\n");
	i = 0;
	while (files_names[i])
		test_readdir(files_names[i++]);

	printf("%d\n", active_opt & U_MIN);
	return (invalid_opt);
}
