#include "ft_ls.h"

/*
** six_month_older:
**
** Check if the given date is older than six month.
** return:
** - 1 if file is older than six month
** - 0 if file is newer than 6 month
*/

static int			six_month_older(time_t file_time)
{
	time_t	now;
	int		six_month;

	time(&now);
	six_month = 60 * 60 * 24 * 30 * 6;
	return (now - six_month > file_time);
}

/*
** keep_year:
**
** Remove the hour of the ctime return by the year.
*/

static void				keep_year(char *date)
{
	char	*year;
	char	*hour;

	year = ft_strrchr(date, ' ');
	*year++ = '\0';
	hour = ft_strchr(date, ':');
	ft_strset(hour - 2, ' ');
	ft_strmove(hour - 1, year);
}

/*
** format_date:
**
** From a single t_file element, format date who will be displayed.
** Select the date according to the sorting option and check if this date is
** newer than six month to set the year if needed.
*/

static void 	format_date(int active_opt, t_file *folder)
{
	time_t	date;
	char	*str_date;

	date = 0;
	if (active_opt & U_MAJ)
		date = folder->info->st_birthtimespec.tv_sec;
	else if (active_opt & U_MIN)
		date = folder->info->st_atimespec.tv_sec;
	else
		date = folder->info->st_mtimespec.tv_sec;
	str_date = ft_strdup(ctime(&date));
	ft_strreplace(str_date, '\n', '\0');
	if (six_month_older(date)) // C faux
		keep_year(str_date);
	else
		str_date[16] = '\0';
	folder->modification_time = str_date;
}

/*
** format_all_date:
**
** Loop over each t_file element to format his date.
*/

void 		format_all_date(int options, t_file *file_list)
{
	while (file_list)
	{
		format_date(options, file_list);
		file_list = file_list->next;
	}
}
