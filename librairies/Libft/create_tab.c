

/*
** create_tab:
**
** Allocate a char ** from a given size. Set all index to NULL.
*/

#include "libft.h"

char **create_tab(int size)
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
