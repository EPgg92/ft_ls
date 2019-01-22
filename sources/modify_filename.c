#include "ft_ls.h"

static int add_char_to_name(char **name, char c)
{
	int len;
	char *tmp;

	len = ft_strlen(*name);
	if (!(tmp = ft_strnew(len + 1)))
		return (-1);
	ft_strcpy(tmp, *name);
	tmp[len] = c;
	ft_strdel(name);
	name = &tmp;
	return (1);
}

int modify_filename(t_file **folder)
{
	t_file *node;

	node = *folder;
	while (node)
	{
		if (add_char_to_name(&node->filename, node->ftype) == -1)
			return (-1);
		node = node->next;
	}
	return (1);
}
