#include "ft_ls.h"

void	print_type(t_file *file)
{
	mode_t	f_mode;

	f_mode = file->data->st_mode;
	S_ISDIR(f_mode) ? ft_putchar('d') : NULL;
	S_ISREG(f_mode) ? ft_putchar('-') : NULL;
	S_ISSOCK(f_mode) ? ft_putchar('s') : NULL;
	S_ISLNK(f_mode) ? ft_putchar('l') : NULL;
	S_ISBLK(f_mode) ? ft_putchar('b') : NULL;
	S_ISFIFO(f_mode) ? ft_putchar('p') : NULL;
	S_ISCHR(f_mode) ? ft_putchar('c') : NULL;
}

void	print_rights(t_file *file)
{
	mode_t	f_mode;

	f_mode = file->data->st_mode;
	f_mode & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	f_mode & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	f_mode & S_IXUSR ? ft_putchar('x') : ft_putchar('-');
	f_mode & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	f_mode & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	f_mode & S_IXGRP ? ft_putchar('x') : ft_putchar('-');
	f_mode & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	f_mode & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	f_mode & S_IXOTH ? ft_putchar('x') : ft_putchar('-');
}
