/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 08:38:27 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:46:37 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define PERSONNAL

# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

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
char			*ft_utoa(unsigned int nbr);
char			*ft_lltoa(long long int nbr);
char			*ft_llutoa(unsigned long long int nbr);
char			*ft_itoabase(unsigned int nbr, const char *base);
char			*ft_ltoabase(unsigned long long nbr, const char *base);
size_t			ft_strlen(const char *str);
size_t			ft_nbrlen(long long int nbr);
size_t			ft_unbrlen(unsigned long long int nbr);
size_t			ft_llnbrlen(long long nbr);
size_t			ft_unbrlen(unsigned long long nbr);
size_t			ft_strnlen(const char *str, size_t n);

/*
** Printing functions
*/

int				ft_putchar(char c);
int				ft_putuchar(unsigned char c);
int				ft_putstr(char const *str);
int				ft_putendl(char const *str);
int				ft_putnbr(int nb);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char const *str, int fd);
int				ft_putendl_fd(char const *str, int fd);
int				ft_putnbr_fd(int nb, int fd);

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
char			*ft_strpbrk(const char *str, const char *charset);
void			ft_strclr(char *str);
char			*ft_strtrim(const char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_fstrjoin(char **s1, char **s2, int free_s1, \
		int free_s2);
char			*ft_strstr(const char *full_str, const char *substring);
char			*ft_strnstr(const char *full_str, const char *substring,\
		size_t len);

void			ft_striter(char *str, void (*fct)(char *));
void			ft_striteri(char *str, void (*fct)(unsigned int, char *));
char			*ft_strmap(const char *str, char (*fct)(char));
char			*ft_strmapi(const char *str, char (*fct)(unsigned int, char));
char			**ft_strsplit(const char *str, const char *charset);
char			*ft_strnew(size_t size);
int				ft_strdel(char **str);
void			ft_strclear(char *str, int from);
int				ft_strdel_out(char **str, int status);
void			ft_strmove(char *begin_str, char *new_begin);

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
** Unicode functions
*/

size_t			ft_wstrlen(wchar_t *str);
size_t			ft_putwchar(wchar_t c);
size_t			ft_putwstr(wchar_t *str);

/*
** Word routine
*/

int				ft_wordlen(const char *string);
int				ft_wordcount(const char *str);
size_t			ft_count(const char *str, const char *charset);

/*
** Caracter compare
*/

int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_incharset(char c, const char *charset);

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
** Extra functions
*/

long long		ft_pow(int nbr, int pow);
int				ft_abs(int nbr);
size_t			determine_bytes(wchar_t c);
size_t			str_byteslen(wchar_t *str);
void			*ft_wstrdel(wchar_t **wstr);
wchar_t			*ft_wstrcpy(wchar_t *s1, wchar_t *s2);
wchar_t			*ft_wstrdup(wchar_t *wstr);

/*
** get_next_line elements
*/

# define BUFF_SIZE 1

typedef struct s_fd	t_fd;

struct			s_fd
{
	char	content[BUFF_SIZE + 1];
	int		fd;
	int		last_read;
	t_fd	*next;
};

int				get_next_line(int fd, char **line);
char			*ft_readfile(int fd);
int				ft_rmdir(char *filename, int recursiv);

#endif
