#include "ft_ls.h"

/*
** join_path:
**
** create relative path of file relatively to the folder.
**
** return value:
** - NULL return if malloc fails.
** - string containing relative path if success.
*/

char		*join_path(char *folder, char *file)
{
	char	*slash;
	int		allocate;

	if (folder == NULL || ft_strequ(".", file) || ft_strequ("..", file))
		return (ft_strdup(file));
	allocate = 0;
	slash = ft_strrchr(folder, '/');
	if (slash == NULL || *(slash + 1) != '\0')
	{
		allocate = 1;
		if (!(folder = ft_strjoin(folder, "/")))
			return (NULL);
	}
	return (ft_fstrjoin(&folder, &file, allocate, 0));
}
