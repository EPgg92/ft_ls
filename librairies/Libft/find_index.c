/*
** find_index:
**
** Return index of a given char in a string. Return -1 if the char is not found.
*/

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
