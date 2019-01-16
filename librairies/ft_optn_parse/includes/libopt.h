#ifndef LIBOPT_H
#define LIBOPT_H

#include "../../Libft/libft.h"
#include <stdio.h>

/*
** Structure to stock option, is a chained list.
**
** next -> next t_optn element.
** name -> argument like -x or --format-like.
** expect_arg --> if an argument is expected.
**                0 mean no arg, 1 otherwise.
** active -> if the argument have been found in argv.
** arg  -> argument if exepected.
*/

typedef struct s_optn	t_optn;

struct s_optn
{
	t_optn *next;
	const char *name;
	int expect_arg;
	int active;
	char *arg;
};


typedef struct s_head_optn	t_head_optn;

struct s_head_optn
{
	int nb_opt_arg;
	int nb_opt_sing;
	int nb_opt_long;
	char *opt_arg;
	char *opt_sing;
	char **opt_long;
	t_optn *next;
	char *illegal_opt;
	char **argv;
	int		argc;
	int		first_arg;
};


int update_head(t_head_optn **head);
int set_head_optn(t_head_optn **head);
int clear_head_optn(t_head_optn **head);
int add_opt_head(t_head_optn **head, char *name_opt, unsigned int opt_arr);



/* Main function for parsing argument */

int	optparse(int argc, char **argv, t_head_optn *head);

/*
**   Functions for lists manipulations
**	- I) List creation
**	- II) Printing
**	- III) Memory freeing
*/

/* I) Function to create t_optn structure.
**
** create_arg : create a t_optn element, whith his name and an argument flag.
**		- name : "-x" Or "--xname"
**		- expect_arg : 0 if no argument, 1 otherwise.
**
** push_front_optn:
**		 create an element at top of the list.
**		 - optn_list : take an already created t_optn element or NULL.
**
** push_end_optn: create an element at the end, before NULL,
**		  create list if needed.
*/

t_optn	*create_optn(const char *name, int expect_arg);
int		push_front_optn(t_optn **optn_list, const char *name, int expect_arg);
int		push_back_optn(t_optn **optn_list, const char *name, int expect_arg);

/* II) Printing functions
**
** print_optn_list --> print an entire list.
** print_optn_node --> print a single element.
*/
void	print_optn_list(t_optn *arg_list);
void	print_optn_node(t_optn *arg_node);
void	print_chained(t_optn *optn_list);

/* III) Memory freeing
**
** clear_optn_list -->  Take a list to free and return 1.
** remove_unactive --> remove element with active flag set to 0.
*/

int	clear_optn_list(t_optn **arg_list);
void	remove_unactive(t_optn **arg_list);



/*
** t_optn list manipulation.
**
*/

t_optn	*get_optn(t_optn *optn_list, const char *name);

/*
** Comparaison function
*/

/* Check option availability */

int				analyse_optn(const char *string, t_head_optn *head);


/* Verification fonctions */
int		activate_optn(char *arg, t_optn **options, t_optn **arg_node);
int		check_optn_arg(t_head_optn *head, t_optn *node, int *index);


int			deplace_option(t_optn **begin, t_optn *node);
int			sort_optn(t_optn **begin_list, t_optn *optn);
void	move_option(t_optn *optn_node, char **argv, int index, int *first_arg);

void		multiple_activation(t_head_optn *head, char *option_list, t_optn **option, int index);

#endif
