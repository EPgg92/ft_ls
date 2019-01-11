/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_readfile.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 16:11:46 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:12:01 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfile(int fd)
{
	char	*content;
	int		readed;
	char	buffer[BUFF_SIZE + 1];
	char	*buffer_pointer;

	content = NULL;
	buffer_pointer = buffer;
	while ((readed = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[readed] = '\0';
		if (content)
		{
			if (!(content = ft_fstrjoin(&content, &buffer_pointer + 0, 1, 0)))
				return (NULL);
		}
		else
		{
			if (!(content = ft_strdup(buffer)))
				return (NULL);
		}
	}
	return (content);
}
