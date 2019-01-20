#include "utils.h"

void print_binary(long nb , int iter)
{
	if (iter)
		print_binary(nb>>1 ,--iter);
	printf("%d", nb % 2 != 0);
}

void print_short(short to_print)
{
	print_binary((long)to_print, 11);
	printf("\n");
}
