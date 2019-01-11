#include <pwd.h>
#include "ft_ls.h"
#include "grp.h"

char	*get_usrname(t_file *file)
{
	struct passwd *user_id;

	if (!(user_id = getpwuid(file->data->st_uid)))
		return (NULL);
	return (user_id->pw_name);
}

char	*get_grpname(t_file *file)
{
	struct group *f_grp;

	if (!(f_grp = getgrgid(file->data->st_gid)))
		return (NULL);
	return (f_grp->gr_name);
}
