/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   std_other_functions.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:23:55 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 11:19:05 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <sys/stat.h>

/*
** get functions for va_args, specific task:
**
** get_p : get a pointer adress, with get_lbase.
** get_big_f : get a char * and read file.
*/

char		*get_p(va_list args, t_prt_opt *options, int *octets)
{
	void	*value;
	char	*format_str;
	char	*fill_char;

	value = va_arg(args, void *);
	if (!(format_str = ft_ltoabase((uintmax_t)value, "0123456789abcdef")))
		return (NULL);
	if (value == NULL && !options->precision)
		ft_strclear(format_str, 0);
	options->flag->hashtag = 1;
	fill_char = "0x";
	if (!(format_str = base_routine(options, format_str, fill_char)))
		return (NULL);
	if (options->flag->positiv && (fill_char = "+"))
		if (!(format_str = ft_fstrjoin(&fill_char, &format_str, 0, 1)))
			return (NULL);
	if (options->flag->space && (fill_char = " "))
		if (!(format_str = ft_fstrjoin(&fill_char, &format_str, 0, 1)))
			return (NULL);
	*octets += ft_strlen(format_str);
	return (format_str);
}

char		*get_big_f(va_list args, t_prt_opt *format_options, int *octets)
{
	char		*filename;
	char		*content;
	int			fd;
	struct stat	file_stat;

	filename = va_arg(args, char *);
	stat(filename, &file_stat);
	if (!S_ISREG(file_stat.st_mode))
		return (ft_strdup("(not regular file)"));
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (ft_strdup("(open failed)"));
	if (!(content = ft_readfile(fd)))
		return (NULL);
	*octets = ft_strlen(content);
	if (format_options->precision != -1 && *octets > format_options->precision)
	{
		*octets = format_options->precision;
		ft_strclear(content, format_options->precision);
	}
	return (content);
}

char		*get_percent(va_list args, t_prt_opt *format_options, int *octets)
{
	char	*formated_str;

	UNUSED(args);
	UNUSED(format_options);
	if (!(formated_str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	formated_str[0] = '%';
	formated_str[1] = '\0';
	*octets = 1;
	return (formated_str);
}
