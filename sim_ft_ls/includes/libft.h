#ifndef LIBFT_H
#define LIBFT_H

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Copying functions */

char	*ft_strcpy(char *dest, const char *src);
int	ft_strlen(const char *str);
int	ft_strnlen(const char *str, unsigned int n);
char	*ft_strncpy(char *dest, const char *src, unsigned int n);
char	*ft_strdup(const char *src);
char	*ft_strndup(const char *src, unsigned int n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);

/* Printing Functions : */

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putlnb(long long int nb);
void	ft_putstr(char const *str);
void	ft_putendl(char const *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char const *str, int fd);
void	ft_putendl_fd(char const *str, int fd);
/* Comparaison functions */

//Flags for the ft_isword function
#ifndef FT_ISWORD_FL

#define NO_SPACE 0
#define SPACE_START 1
#define SPACE_END 1

#endif

int	ft_strcmp(const char *s1, const char *s2);
int	ft_istrcmp(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strchr(char *str, int c);
char	*ft_strrchr(char *str, int c);
char	*ft_strstr(char *str, char *to_find);
int	ft_isdigit(int c);
int	ft_isascii(int c);
int	ft_isalnum(int c);
int	ft_isprint(int c);
int	ft_isalpha(int c);
int	ft_isspace(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);
int	ft_isword(const char *string, int check_start, int check_end);
int	ft_isvarname(const char *string, int check_start, int check_end);
int	ft_start_with(const char *string, const char *substring);
int	ft_end_with(const char *string, const char *substring);


/* Converting functions */

int	ft_atoi(char *string);
char	*ft_itoa(int nb);
char	*ft_itoa_base(int nb, int base);

/* Function to work with array of strings */

int	ft_move_strtab(char **tab, int len, int from, int to);

/* To classify */

char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	**ft_strsplit(char const *s, char c);
char	*ft_strtrim(char const *s);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ptr);
char	*ft_strnew(size_t size);
void	ft_strclr(char *str);
void	ft_strdel(char **str_ptr);
char	*ft_strmap(char const *s, char (*fct)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*  Chained lists  */

typedef struct	s_list
{
	struct s_list	*next;
	void		*data;
}		t_list;

t_list		*ft_create_elem(void *data);
void		ft_list_push_back(t_list **begin_list, void *data);
void		ft_list_push_front(t_list **begin_list, void *data);
void		ft_list_clear(t_list **begin_list);


/* Path manipulation */

char	*ft_foldname(char *filename);

/* Others */

void	ft_swap(int *a, int *b);
void	ft_strswap(char **str_a, char **str_b);
int	ft_pow(int nb, int pow);
long long int ft_long_pow(int nb, int pow);

/* TEST */

int	word_count(char const *str, char c); 

#endif
