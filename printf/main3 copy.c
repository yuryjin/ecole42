#include "./components/includes/ft_printf.h"

int main(int argc, char const *argv[])
{

//	printf("%llx", 9223372036854775807);
//	printf("\n");
//	ft_printf("%llx", 9223372036854775807);

	/*
	printf("%5.2x", 5427);
	printf("\n");
	ft_printf("%5.2x", 5427);
	ft_printf("\n");	*/
	/*
	printf("%s  ", "this is a string");
	printf("\n");
	ft_printf("%s  ", "this is a string");
	ft_printf("\n");
	*/

	/*
	printf("%-40a", 42.5);
	printf("\n");
	ft_printf("%a", 42.5);
	printf("\n");
	*/

	printf("%-40a", 42.5);
	printf("\n");
	ft_printf("%a", 42.5);
	printf("\n");

	return 0;
}
