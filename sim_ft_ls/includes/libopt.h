#ifndef LIBOPT_H
#define LIBOPT_H

#include "libft.h"
#include "libprintf.h"

#define PRINT ft_baby_printf

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


/* Main function for parsing argument */

int	optparse(int argc, char **argv, t_optn **optn_required);

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
void	push_front_optn(t_optn **optn_list, const char *name, int expect_arg);
void	push_back_optn(t_optn **optn_list, const char *name, int expect_arg);

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

int	ft_is_optn(const char *string);


/* Verification fonctions */
int	ft_optn_in(t_optn *optn_list, char *arg, t_optn **arg_node);
int	check_optn_arg(t_optn *node, int argc, char **argv, int *index);

#endif