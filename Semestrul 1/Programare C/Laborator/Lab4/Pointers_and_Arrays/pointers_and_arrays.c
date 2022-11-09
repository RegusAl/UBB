#include <stdio.h>
#include <stdlib.h>

int main() {
	int vec[3];
	vec[0] = 1;
	vec[1] = 2;
	vec[2] = 3;
	printf("vec[2]=%d\n", vec[2]);
	// same as printf("vec[2]=%d\n", *(vec+2));
	return 0;
}
