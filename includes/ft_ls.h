#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <sys/stat.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <limits.h> // PATH_MAX

typedef struct s_file t_file;

struct		s_file
{
	struct stat	*info; // int lstat(const char *restrict path, struct stat *restrict buf);
	char		*path;
	char		*pw_name;// struct passwd *getpwuid(uid_t uid);
	char		*gr_name;//	struct group *getgrgid(gid_t gid)
	char    	*modification_time; //char * ctime(const time_t *clock);
	char		*symbolic_link;// ssize_t readlink(const char *restrict path, char *restrict buf, size_t bufsize);
	char		ftype;
	char		xattr; // ssize_t listxattr(const char *path, char *namebuf, size_t size, int options);
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
#endif
