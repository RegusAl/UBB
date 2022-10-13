#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
	printf("An int occupies: %d bytes \n", sizeof(int));
	printf("Smallest int is: %d\n", INT_MIN);
	printf("Greatest int is: %d\n", INT_MAX);
	printf("A double occupies: %d bytes \n", sizeof(double));
	printf("Smallest double is: %e\n", DBL_MIN);
	printf("Greatest double is: %e\n", DBL_MAX);
	return 0;
}
