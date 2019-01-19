#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "libft.h"
#include "ft_ls.h"


static int is_valid_opt(char *str)
{
	int i;

	i = 0;
	if (str[i++] == '-' && ft_strnlen(str, 2) > 1)
	{
		while (str[i])
		{
			if (!ft_strchr(ALL_OPT, str[i]))
			{
				return(i); // str[i] is not a valid option
			}
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

static int find_index(char* str, char c)
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

static short set_active_opt(short opt, char first)
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

static short set_active_multi_opt(short opt, char *opt_name)
{
	int i;
	i = 1;

	while(opt_name[i])
		opt = set_active_opt(opt, opt_name[i++]);
	return (opt);
}

static char **create_tab(int size)
{
	int i;
	char **tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i <= size)
		tab[i++] = NULL;
	return (tab);
}






t_file *create_tfile(char *path)
{
	t_file *node;

	if (!(node = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	node->path = NULL;
	node->pw_name = NULL;
	node->gr_name = NULL;
	node->modification_time = NULL;
	node->symbolic_link = NULL;
	node->next = NULL;
	if (!(node->info = (struct stat*)malloc(sizeof(struct stat))))
		return (/*freeaNULL*/NULL);
	if (!(node->path = ft_strdup(path)))
		return (/*freeaNULL*/NULL);
	return (node);
}

/*
static int test_readdir(char *name_dir)
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
}*/

static int		option_fill(char ***argv, char **files_names, int *index)
{
	int		invalid_opt;
	int		active_opt;
	int		error;

	active_opt = 0;
	*argv += 1;
	error = 1;
	while (**argv && ft_strcmp(**argv, "--"))
	{
		if (((invalid_opt = is_valid_opt(**argv)) >= 0))
		{
			if (invalid_opt != 0)
			{
				ft_printf("ls: illegal option -- %c\n", argv[0][0][invalid_opt]);
				return (-1);
			}
			active_opt = set_active_multi_opt(active_opt, **argv);
			ft_printf("value : %d\n", active_opt);
		}
		else
		{
			error *= (files_names[*index] = ft_strdup(**argv)) == NULL ? 0 : 1;
			*index += 1;
		}
		*argv += 1;
	}
	ft_printf("out : %d\n", active_opt);
	return (error == 0 ? free_str_array(&files_names, -1) : active_opt);
}

int		parse_argv_option(int argc, char **argv, char ***files_names)
{
	short	active_opt;
	int		index;
	int		error;

	active_opt = 0;
	index = 0;
	error = 1;
	
	if (!(*files_names = create_tab(argc)))
		return (-1);
	printf("%s\n", *argv);

	if ((active_opt = option_fill(&argv, *files_names, &index)) == -1)
		return (-1);
	ft_printf("Inside %d\n", active_opt);
	while (*argv)
		error *= (*files_names[index++] = ft_strdup(*argv++)) == NULL ? 0 : 1;
	if (*files_names[0] == NULL)
		error *= (*files_names[0] = ft_strdup(".")) == NULL ? 0 : 1;
	return (error == 0 ? free_str_array(files_names, 0) : active_opt);
}
