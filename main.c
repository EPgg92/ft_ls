#include <time.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	time_t date;

	time(&date);
	printf("%s\n", ctime(&date));
}
