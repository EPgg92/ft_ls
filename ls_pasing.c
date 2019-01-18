#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "librairies/Libft/libft.h"

char *ALL_OPT = "utromlaUSRF1";
				//1FRSUalmortu
short RESET_SORT = 0b000110000001;
short RESET_PRINT = 0b100000111000;

int is_valid_opt(char *str)
{
	int i;

	i = 0;
	if (str[i++] == '-' && strlen(str) > 1)
	{
		while (str[i])
			if (!strchr(ALL_OPT, str[i++]))
				return(i); // str[i] is not a valid option
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

int find_ind(char* str, char c)
{
	int i;

	i = 0;
	while (str[i])
	 	if (str[i++] == c)
			return (i - 1);
	return (-1);
}

short set_active_opt(short opt, char first)
{
	short tmp;
	int span;

	if (first != 'o')
	{
		tmp = 1;
		span = find_ind(ALL_OPT, first);
		tmp <<= span;
	}
	else
		tmp = 40; // speciation of l with o
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


int main(int argc, char **argv)
{
	int		no_hyphen;
	short	active_opt;
	int		invalid_opt;
	char	**files_names;
	int		i;

	no_hyphen = 1;
	active_opt = 0;
	i = 0;
	if (!(files_names = create_tab(argc)))
		return (-1);
	while (*++argv && active_opt >= 0)
	{
		if ((no_hyphen = strncmp(*argv, "--", 3)) && !(invalid_opt = is_valid_opt(*argv)))
			active_opt = set_active_multi_opt(active_opt, *argv);
		else
			files_names[i++] = ft_strdup(*argv);
	}
	if (files_names[0] == NULL)
		files_names[0] = ft_strdup(".");
	// to rm ...
	printf("Les options actives:\n");
	printf("%s\n", "1FRSUalmortu");
	print_short(active_opt);
	printf("Fichiers/dossiers à lister:\n");
	i = 0;
	while (files_names[i])
		printf("%s\n", files_names[i++]);
	// stop
	return (0);
}
