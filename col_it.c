#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int get_max(int argc, char **argv)
{
	int max;
	int i;
	int tmp;

	max = 0;
	i = 0;
	while (i < argc)
		if ((tmp = strlen(argv[i++])) > max)
			max = tmp;
	return (max);
}

void printf_space(char *str, int max)
{
	int len;

	printf("%s", str);
	len = strlen(str);
	while (len++ <= max)
		printf(" ");
}

int main(int argc, char **argv)
{
    struct winsize w;
	int term_width;
	int max;
	int nb_name_per_line;
	int nb_line;

	argv++;
	argc--;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	term_width = w.ws_col ;
	max = get_max(argc, argv);
	nb_name_per_line = term_width / max;
	nb_line = argc / nb_name_per_line + 1;
	nb_name_per_line = argc / nb_line;

	int i;
	int j;
	int k;

	printf("term_width : %d\n", term_width);
	printf("nb_name_per_line : %d\n", nb_name_per_line);
	printf("nb_line : %d\n", nb_line);
	i = 0;
	j = 0;
	k = 0;
	while (i <= nb_line && k < argc)
	{
		while (j < nb_name_per_line && k < argc)
		{
				printf_space(argv[k++], max);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
    return 0;
}
