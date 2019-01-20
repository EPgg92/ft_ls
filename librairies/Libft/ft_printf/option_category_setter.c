/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option_category_setter.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:48:23 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 18:16:40 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

/*
** set_category:
**
** Set up the category attribute in a t_prt_opt structure.
** Check depeding of the specifier and the modifier wich kind
** of value set.
**
** Category values:
** - 1 Number like format
** - 2 string like format
** - 3 wchar_t like format
*/

void		set_category(t_prt_opt *format_option)
{
	if (ft_incharset(format_option->specifier, "pdDioOuUxX"))
		format_option->category = 1;
	else if (ft_incharset(format_option->specifier, "scF%r"))
	{
		if (ft_strequ(format_option->modifier, "l"))
			format_option->category = 3;
		else
			format_option->category = 2;
	}
	else if (ft_incharset(format_option->specifier, "SC"))
		format_option->category = 3;
}

/*
** set_full_specifier:
**
** Set up the full_specifier attribute of t_prt_opt, it's the result
** of modifier + specifier concatenation.
** Free and old one if needed.
*/

int			set_full_specifier(t_prt_opt *options)
{
	int len;

	if (options->full_specifier)
		free(options->full_specifier);
	len = ft_strlen(options->modifier) + 1;
	options->full_specifier = (char *)malloc(sizeof(char) * (len + 1));
	if (!(options->full_specifier))
		return (0);
	ft_strcpy(options->full_specifier, options->modifier);
	options->full_specifier[len - 1] = options->specifier;
	options->full_specifier[len] = '\0';
	return (1);
}
