#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <sys/stat.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <limits.h> // PATH_MAX

typedef struct s_file t_file;

struct s_file
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

#endif
