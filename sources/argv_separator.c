#include "ft_ls.h"

/*
** is_folder:
**
** Check if the given filename is a folder or not. Follow the symlink
** depending of the given options.
** Display an error message using errno (perror) if an error occur.
**
** return value:
** - -1 if an error occur.
** - Not 0 (1 ?) value if the file is a folder.
*/

static int			is_folder(char *filename, int options)
{
	struct stat		file_info;
	int				error;

	error = options & L_MIN ? lstat(filename, &file_info) : \
								stat(filename, &file_info);
	if (error == -1)
	{
		ft_printf("ls: ");
		perror(filename);
		return (-1);
	}
	return (S_ISDIR(file_info.st_mode));
}

/*
** delete_string:
**
** Remove the first index of char ** element.
** Free the element and move to the front the rest of the array.
*/

static void			delete_string(char **string_list)
{
	int		index;

	index = 1;
	ft_strdel(string_list);
	while (string_list[index])
	{
		string_list[index - 1] = string_list[index];
		index++;
	}
	string_list[index - 1] = NULL;
}

/*
** split_argv_filetype:
**
** Parse a list of filename. Add each folder in a t_file list. Keep all other
** filetype in the char ** argument, remove each folder of this array of string.
** Display an error message if the filename doesn't exist.
**
** return value:
** - -1 if an allocation error occur.
** - 1 if the operation succeed.
*/

int					split_argv_filetype(char **files, int options, \
										t_file **folder_list)
{
	int		index;
	int		type_error;
	int		total_files;

	index = 0;
	*folder_list = NULL;
	total_files = ft_arraylen(files);
	sort_str_array(files, ft_strcmp);
	while (files[index])
	{
		type_error = is_folder(files[index], options);
		if (type_error == 0)
			index++;
		else
		{
			if (type_error != -1)
				if (push_file(folder_list, NULL, files[index]) == -1)
					return (free_folder(folder_list, -1));
			delete_string(files + index);
		}
	}
	return (total_files);
}
