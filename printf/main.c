#include "includes/ft_printf.h"

int main(int argc, char const *argv[])
{
	printf("%-*.*jd\n", 8, 12, 13);
	ft_printf("%-*.*jd\n", 8, 12, 1334);
	return 0;
}