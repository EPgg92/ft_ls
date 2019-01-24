#include "ft_ls.h"

/*
** add_char_to_name:
**
** Make a concatenation with a string and a single char.
*/

static int	add_char_to_name(char **name, char c)
{
	int		len;
	char	*tmp;

	len = ft_strlen(*name);
	if (!(tmp = ft_strnew(len + 1)))
		return (-1);
	ft_strcpy(tmp, *name);
	tmp[len] = c;
	ft_strdel(name);
	*name = tmp;
	return (1);
}

/*
** set_file_type:
**
** Add extension to each t_file->filename element according to the file
** type. File type character is stored in t_file->ftype.
*/

int			set_file_type(t_file **folder)
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
