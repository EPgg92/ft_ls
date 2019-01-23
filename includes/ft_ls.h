#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <unistd.h>
# include <uuid/uuid.h>

/*
** Bonus
**
** sys/ioctl.h to display columns relatively to the term size.
** imits.h to
*/

# include <limits.h>
# include <sys/ioctl.h>

/*
** All constants
*/

# define ALL_OPT		"utromlaUSRF1"
# define RESET_SORT 	0b000110000001
# define RESET_PRINT 	0b100000111000
# define U_MIN			0b1
# define T_MIN 			0b10
# define R_MIN			0b100
# define O_MIN 			0b1000
# define M_MIN			0b10000
# define L_MIN 			0b100000
# define A_MIN			0b1000000
# define U_MAJ			0b10000000
# define S_MAJ			0b100000000
# define R_MAJ			0b1000000000
# define F_MAJ			0b10000000000
# define OPT_1			0b100000000000
# define RIGHT_LEN		12
# define FOLDER			1
# define FILES			2

typedef struct s_file t_file;
struct		s_file
{
	char		*filename;
	int			file_len;
	char		*gr_name;
	char		*path;
	char		*pw_name;
	char		ftype;
	char		right[RIGHT_LEN];
	char		symbolic_link[PATH_MAX];
	char    	*modification_time;
	struct stat	*info;
	t_file		*next;
};

typedef struct s_file_head	t_file_head;
struct		s_file_head
{
	char		*print_pattern;
	int			block_number;
	int			len_filename;
	int			len_group;
	int			len_size;
	int			len_symlink;
	int			len_user;
	int			opts;
	int			print_foldname;
	int			window_width;
	int			file_printed;
	int 		files_number;
	t_file		*arg_fold;
	t_file		*work_list;
};

int			parse_argv_option(int argc, char **argv, char ***files_names);
int			split_argv_filetype(char **files, int options, t_file **folder_list);

/*
** Utils for t_file elements.
*/

int			free_file_node(t_file **folder, int status);
int			free_folder(t_file **folder, int status);
int			create_tfile(char *parent, char *path, t_file **node);
t_file_head	*t_file_head_initialisation(void);
int			push_file(t_file **folder, char *parent_dir, char *path);
void		free_file_head(t_file_head **head_file);

/*
** Informations getter
*/

void		format_all_date(int options, t_file *file_list);

/*
** Directory parsing
*/

int			parse_folder(char *folder, t_file **folder_list, int active_opt);
int			stock_file_list(char **files, t_file **list_file);

void		print_folder(t_file *folder);

/*
** Sorting funcitons
*/

typedef int	(*file_cmp)(t_file *, t_file *);
void		insert_sort(t_file **folder, file_cmp cmp_function);

int			modif_compare(t_file *file_1, t_file *file_2);
int			time_compare(t_file *file_1, t_file *file_2);
int			access_compare(t_file *file_1, t_file *file_2);
int			creation_compare(t_file *file_1, t_file *file_2);
int			ascii_compare(t_file *file_1, t_file *file_2);
int			size_compare(t_file *file_1, t_file *file_2);
void 		reverse_files(t_file **files);

/*
** t_file printing process
*/

char		*get_printing_pattern(t_file_head *head_file);
void		select_sort(int active_opt, t_file **folder);
void		set_maximum_info(t_file_head *head_file);
int			process_manager(char **file_or_dir, t_file_head *head, int type);
int			t_file_list_len(t_file *file_list);
int 		modify_filename(t_file **folder);



typedef void	(*print_mode)(t_file_head *);

//void 		print_manager(t_file_head *head_file, print_mode prt_fct, char *folder);

void		l_print(t_file_head *);
void		basic_print(t_file_head *);
void		one_print(t_file_head *);
void		o_print(t_file_head *);
void		m_print(t_file_head *);
int			select_print(t_file_head *head, char *folder);

#endif
