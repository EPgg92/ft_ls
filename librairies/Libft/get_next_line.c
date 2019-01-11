/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 06:38:17 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:00:40 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Get t_fd element corresponding to the specified file descriptor.
** Create a new t_fd if needed.
*/

static t_fd		*get_fd_elem(t_fd **lst, int fd)
{
	t_fd	*fd_node;
	t_fd	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(fd_node = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	fd_node->fd = fd;
	fd_node->next = *lst;
	fd_node->last_read = 0;
	ft_bzero(fd_node->content, BUFF_SIZE + 1);
	*lst = fd_node;
	return (fd_node);
}

/*
** Free properly only a signle element or an entire list
** action variable is a flag to choose element to free
** action value :
** - 1 free element
** - 2 free entire list
*/

int				free_fd(t_fd **lst, t_fd *curr_fd, int action, int status)
{
	t_fd *tmp;
	t_fd *prev_fd;
	t_fd *next_fd;

	tmp = *lst;
	prev_fd = NULL;
	while (tmp)
	{
		next_fd = tmp->next;
		if (action == 1 && prev_fd == NULL && curr_fd == tmp)
			*lst = (*lst)->next;
		else if (action == 1 && prev_fd && curr_fd == tmp)
			prev_fd->next = curr_fd->next;
		prev_fd = tmp;
		if ((action == 1 && curr_fd == tmp) || action == 2)
		{
			free(tmp);
			if (action == 1)
				break ;
		}
		tmp = next_fd;
	}
	if (action == 2)
		*lst = NULL;
	return (status);
}

/*
** Check in t_fd->content element if we can extract a substring from a newline
** Return :
** - 1 if extract_str get a string
** - 0 if no newline found
** - -1 if malloc error occur
*/

static int		extract_str(t_fd *fd_node, char **substr)
{
	char	*next_newline;
	char	*content;

	content = fd_node->content;
	*substr = NULL;
	if ((next_newline = ft_strchr(content, '\n')))
	{
		if (!(*substr = ft_strsub(content, 0, next_newline - content)))
			return (-1);
		ft_strmove(content, next_newline + 1);
		return (1);
	}
	return (0);
}

static int		read_next_buf(t_fd *fd_node, char **line)
{
	int		buf;
	char	*old_content;

	if (!(old_content = ft_strdup(fd_node->content)))
		return (-1);
	*line = *line ? ft_fstrjoin(line, &old_content, 1, 1) : old_content;
	if (*line == NULL)
		return (-1);
	buf = read(fd_node->fd, fd_node->content, BUFF_SIZE);
	if (buf > 0)
		fd_node->content[buf] = '\0';
	else if (buf == 0)
	{
		ft_bzero(fd_node->content, ft_strlen(fd_node->content));
		if (fd_node->last_read)
			return (0);
		else if (**line && (fd_node->last_read = 1))
			return (-2);
	}
	return (*line ? buf : -1);
}

/*
** get_next_line:
**
** Read a single line on a given file descriptor
**
** return value:
** => 1 if a line have been read
** => 0 if the entire file been read
** => -1 if an error occured
*/

int				get_next_line(const int fd, char **line)
{
	static t_fd *fd_lst;
	t_fd		*curr_fd;
	char		*rd_line;
	int			extract_res;

	if (fd < 0 || (curr_fd = get_fd_elem(&fd_lst, fd)) == NULL)
		return (fd < 0 ? -1 : free_fd(&fd_lst, curr_fd, 2, -1));
	*line = NULL;
	while ((extract_res = extract_str(curr_fd, &rd_line)) != -1)
	{
		if (extract_res == 0)
		{
			if ((extract_res = read_next_buf(curr_fd, line)) < 0)
				return (extract_res == -2 ? 1 : extract_res);
			if (extract_res == 0)
				return (free_fd(&fd_lst, curr_fd, 1, 0) || ft_strdel(line));
		}
		else
		{
			*line = *line ? ft_fstrjoin(line, &rd_line\
					, 1, 1) : rd_line;
			return (*line ? 1 : -1);
		}
	}
	return (-1);
}
