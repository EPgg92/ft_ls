#ifndef FT_LS_H
#define FT_LS_H

#include "libft.h"
#include "libprintf.h"
#include "libopt.h"
#include <sys/stat.h>
#define PRT ft_baby_printf

typedef struct stat	t_stat;
typedef struct s_file t_file;

struct s_file
{
	t_file *next;
	char *name;
	struct stat *data;
	t_file *fold_child;
	char *abs_path;
};

/* Functions for option parsing */

typedef int (*t_fct_cmp)(t_file *, t_file *);
#include "optn_vars.h"

int	argv_parse(int argc, char **argv, t_optn_var **optns_var);
t_file	*dir_parser(const char *dir, int recursiv);
void	print_option(t_optn_var *var_list);
t_optn_var	*init_optn_var(void);

/* Manipulation of the chained list */

t_file	*create_file_elem(const char *name, t_stat *f_info, const char *dir);
void	push_front_file(t_file **file_list, const char *name, t_stat *f_info, const char *dir);
t_file	*push_back_file(t_file **file_list,  const char *name, t_stat *f_info, const char *dir);

void	print_file_chained(t_file *file_list);
void	tree_print(t_file *file_list);

/* Freeing memory */

void	free_single_file(t_file **file);
void	free_folder(t_file **folder);

/* Comparaison functions */

void	reverse_files(t_file **files);
#define LIST_TYPE t_file
void	reverse_list(LIST_TYPE **list);

void	sort_files(t_file **files, int (*cmp)(t_file *, t_file *));

int	alpha_cmp(t_file *f_one, t_file *f_two);
int	modif_time_cmp(t_file *f_one, t_file *f_two);
int	size_cmp(t_file *f_one, t_file *f_two);


/*  Rights access functions  */

void	print_type(t_file *file);
void	print_rights(t_file *file);
void	print_links(t_file *file);
char	*get_usrname(t_file *file);
char	*get_grpname(t_file *file);
char	*time_modif(t_file *file);

void	folder_print(const char *fold, t_file *file_list, t_optn_var *optns);


void	remove_hidden(t_file **f_list, int keep_point, int keep_dbpoint);

#endif
