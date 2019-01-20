#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <sys/stat.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <time.h>
# include <limits.h> // PATH_MAX
# include <stdio.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/acl.h>

typedef struct s_file t_file;
typedef int	(*file_cmp)(t_file *, t_file *);

struct		s_file
{
	struct stat	*info;
	char		*path;
	char		*filename;

	char		*pw_name;
	char		*gr_name;
	char    	*modification_time;
	char		symbolic_link[PATH_MAX];// ssize_t readlink(const char *restrict path, char *restrict buf, size_t bufsize);
	char		ftype;
	//char		xattr; // ssize_t listxattr(const char *path, char *namebuf, size_t size, int options);
	t_file		*next;
};

int			parse_argv_option(int argc, char **argv, char ***files_names);
#define ALL_OPT "utromlaUSRF1"
				//1FRSUalmortu
#define RESET_SORT 0b000110000001
#define RESET_PRINT 0b100000111000

# define U_MIN 0b1
# define T_MIN 0b10
# define R_MIN 0b100
# define O_MIN 0b1000
# define M_MIN 0b10000
# define L_MIN 0b100000
# define A_MIN 0b1000000
# define U_MAJ 0b10000000
# define S_MAJ 0b100000000
# define R_MAJ 0b1000000000
# define F_MAJ 0b10000000000
# define OPT_1 0b100000000000

int			test_readdir(char *name_dir);

/*
** Utils for t_file elements.
*/

int			free_file_node(t_file **folder, int status);
int			free_folder(t_file **folder, int status);
int			create_tfile(char *parent, char *path, t_file **node);
int			push_file(t_file **folder, char *parent_dir, char *path);

/*
** Directory parsing
*/

int			parse_folder(char *folder, t_file **folder_list);
void		print_folder(t_file *folder);
void		insert_sort(t_file **folder, file_cmp cmp_function);

#endif
