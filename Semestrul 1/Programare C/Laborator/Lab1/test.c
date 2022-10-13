#include <stdio.h>

int main() {
	int sir[5] = {1, 2, 3, 4, 5}, i;
	int *p;
	p = &sir[2];
	*p = 10;
	for(i = 0; i < 4; i++)
		printf("%d, ", sir[i]);
		printf("%d\n", sir[4]);
	return 0;
}
