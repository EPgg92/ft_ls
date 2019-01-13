/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 08:38:27 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 10:40:41 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define PERSONNAL

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_tolower(int c);
int				ft_toupper(int c);

int				ft_atoi(const char *string);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *str);
size_t			ft_strnlen(const char *str, size_t n);

/*
** Printing functions
*/

void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_putendl(char const *str);
void			ft_putnbr(int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr_fd(int nb, int fd);

/*
**	String routine
*/

char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strdup(const char *src);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_fstrchr(const char *str, int (*fct)(int));
char			*ft_fstrrchr(const char *str, int (*fct)(int));
void			ft_strclr(char *str);
char			*ft_strtrim(const char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strstr(const char *full_str, const char *substring);
char			*ft_strnstr(const char *full_str, const char *substring,\
							size_t len);

void			ft_striter(char *str, void (*fct)(char *));
void			ft_striteri(char *str, void (*fct)(unsigned int, char *));
char			*ft_strmap(const char *str, char (*fct)(char));
char			*ft_strmapi(const char *str, char (*fct)(unsigned int, char));
char			**ft_strsplit(const char *str, char delim);
char			*ft_strnew(size_t size);
void			ft_strdel(char **str);

/*
** Strings array routine
*/

int				ft_move_strtab(char **tab, int len, int from, int to);

/*
** Comparaison functions
*/

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_istrcmp(const char *s1, const char *s2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_start_with(const char *string, const char *subset);

/*
** Word routine
*/

int				ft_wordlen(const char *string);
int				ft_wordcount(const char *str);

/*
** Caracter compare
*/

int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);

/*
** Memory functions
*/

void			*ft_memset(void *b, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *src, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ptr);

/*
** Pointer functions
*/

void			ft_strswap(char **str_a, char **str_b);
void			ft_swap(int *a, int *b);

/*
** List functions
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Extra functions
*/

long long		ft_pow(int nbr, int pow);

#endif
