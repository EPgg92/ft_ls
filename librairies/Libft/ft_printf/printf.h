/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_bis.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 09:55:42 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 18:17:09 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <inttypes.h>
# include <limits.h>
# include <fcntl.h>

int			ft_printf(char *format, ...);

# define UNUSED(x) (void) (x)

typedef struct s_prt_opt	t_prt_opt;
typedef struct s_flags	t_flags;

struct		s_flags
{
	int negativ;
	int positiv;
	int hashtag;
	int space;
	int zero;
};

/*
** t_prt_opt
**
** Use to set up all available option on a format.
**
** category:
** 1 - number like format.
** 2 - string like format.
** 3 - wstring like format.
*/

struct		s_prt_opt
{
	t_flags	*flag;
	size_t	field;
	int		precision;
	char	*modifier;
	char	specifier;
	char	*full_specifier;
	int		category;
};

typedef struct s_fcts	t_fcts;
typedef struct s_wfcts	t_wfcts;
typedef struct s_fct_manager	t_fct_manager;
typedef char *(*t_build_fct)(va_list arg, t_prt_opt *opt, int *octets);
typedef wchar_t *(*t_unicode_fct)(va_list arg, t_prt_opt *opt, int *octets);

struct		s_fct_manager
{
	t_fcts	*std_fcts;
	t_wfcts	*uni_fcts;
};

struct		s_fcts
{
	t_fcts		*next;
	char		*key;
	t_build_fct	string_maker;
};

struct		s_wfcts
{
	t_wfcts			*next;
	char			*key;
	t_unicode_fct	string_maker;
};

/*
** Function for format option parsing.
*/

void		parse_flags(char **format, t_flags *flag);
int			parse_option(char **format, t_prt_opt **specifier_opt);
void		parse_modifier(char **format, t_prt_opt *options);
void		parse_field(char **format, t_prt_opt *options);
void		parse_precision(char **format, t_prt_opt *options);
void		set_category(t_prt_opt *options);
int			set_full_specifier(t_prt_opt *options);
int			free_prt_opt(t_prt_opt **format_option, int status);
t_prt_opt	*alloc_option(void);

void		set_base_choice(t_prt_opt *options, char **fill_start, char **base);
char		*base_routine(t_prt_opt *options, char *format_str, char *fill_chr);
int			is_specifier(int c);
int			is_flag(int c);
int			set_nbfield(t_prt_opt *options, char **formated_str, int *octets);
int			set_strfield(t_prt_opt *options, char **formated_str, int *octets);
int			set_unicode_field(t_prt_opt *option, wchar_t **str, int *octets);

int			display_ascii(va_list args, t_prt_opt *option, t_fcts *prt_manager);
int			display_unicode(va_list args, t_prt_opt *option, \
							t_wfcts *prt_manager);

/*
** Function to create formated strings.
*/

char		*get_s(va_list args, t_prt_opt *options, int *octets);
char		*get_r(va_list args, t_prt_opt *options, int *octets);
char		*get_c(va_list args, t_prt_opt *options, int *octets);
char		*get_u(va_list args, t_prt_opt *options, int *octets);
char		*get_lu(va_list args, t_prt_opt *options, int *octets);
char		*get_llu(va_list args, t_prt_opt *options, int *octets);
char		*get_h_hhu(va_list args, t_prt_opt *options, int *octets);
char		*get_d(va_list args, t_prt_opt *options, int *octets);
char		*get_ld(va_list args, t_prt_opt *options, int *octets);
char		*get_lld(va_list args, t_prt_opt *options, int *octets);
char		*get_h_hhd(va_list args, t_prt_opt *options, int *octets);
char		*get_base(va_list args, t_prt_opt *options, int *octets);
char		*get_lbase(va_list args, t_prt_opt *options, int *octets);
char		*get_llbase(va_list args, t_prt_opt *options, int *octets);
char		*get_h_hhbase(va_list args, t_prt_opt *option, int *octets);
char		*get_p(va_list args, t_prt_opt *options, int *octets);
wchar_t		*get_big_c(va_list args, t_prt_opt *options, int *octets);
wchar_t		*get_big_s(va_list args, t_prt_opt *options, int *octets);
char		*get_big_f(va_list args, t_prt_opt *options, int *octets);
char		*get_percent(va_list args, t_prt_opt *options, int *octets);
int			set_number_precision(char **formated_str, int precision);
char		*base_routine(t_prt_opt *options, char *format, char *fill_char);

/*
** Utils for t_fcts chained list.
*/

# define T_MANAGER t_fct_manager

T_MANAGER	*setup_functions(void);
int			push_element(t_fcts **list_fct, char *key, t_build_fct format_fct);
void		*free_fcts_list(t_fcts **list);
void		*free_manager(t_fct_manager **manager);
void		*free_t_wfcts_list(t_wfcts **unicode_list);
int			push_unicode_elem(t_wfcts **unicode_lst, char *key, \
									t_unicode_fct fct);

#endif
