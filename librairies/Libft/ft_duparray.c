#include "libft.h"

static int	array_size(char **array)
{
	int index;

	index = 0;
	while (array[index])
		index++;
	return (index);
}

char		**ft_duparray(char **array)
{
	char	**duplicate;
	int		index;

	if (!(duplicate = (char **)malloc(sizeof(char *) * (array_size(array) + 1))))
		return (NULL);
	index = 0;
	while (*array)
	{
		duplicate[index] = ft_strdup(*array++);
		if (duplicate[index] == NULL)
		{
			free_str_array(&array);
			return (NULL);
		}
		index++;
	}
	duplicate[index] = NULL;
	return (duplicate);
}
