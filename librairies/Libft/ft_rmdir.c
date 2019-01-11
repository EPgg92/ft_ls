/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rmdir.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 16:08:34 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 16:09:35 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include "libft.h"

#define LINUX
#ifdef LINUX
# define MODE(x) x.st_mode
#endif

static int		check_upper_dir(char *dirname, char *filename)
{
	if (ft_strequ(filename, "..") || ft_strequ(filename, "."))
		return (1);
	else if (ft_strequ(filename, dirname))
		return (1);
	return (0);
}

static char		*format_file(char *basedir, char *filename)
{
	int		dirlen;
	char	*formatted;

	dirlen = ft_strlen(basedir);
	if (basedir[dirlen - 1] == '/')
		return (ft_strjoin(basedir, filename));
	formatted = ft_strnew(dirlen + 1 + ft_strlen(filename));
	if (!formatted)
		return (NULL);
	ft_strcpy(formatted, basedir);
	formatted[dirlen] = '/';
	ft_strcpy(formatted + dirlen + 1, filename);
	return (formatted);
}

static int		delete_dir(char *dirname, int recursiv)
{
	DIR				*directory;
	struct dirent	*file_buf;
	char			*new_filename;

	if (recursiv == 0)
		return (0);
	if (!(directory = opendir(dirname)))
		return (-1);
	while ((file_buf = readdir(directory)))
	{
		if (!(new_filename = format_file(dirname, file_buf->d_name)))
		{
			free(directory);
			return (-1);
		}
		if (check_upper_dir(dirname, file_buf->d_name) == 0)
			ft_rmdir(new_filename, recursiv);
		free(new_filename);
	}
	free(directory);
	rmdir(dirname);
	return (0);
}

int				ft_rmdir(char *filename, int recursiv)
{
	struct stat		file_stat;
	int				res;

	res = stat(filename, &file_stat);
	if (res == -1)
		return (-1);
	if (S_ISDIR(MODE(file_stat)))
		return (delete_dir(filename, recursiv));
	else
		return (unlink(filename));
	return (-1);
}
