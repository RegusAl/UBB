#include <stdio.h>

int nr1, nr2;
int *ptr;

int main() {
	nr1 = 1;
	nr2 = 2;
	ptr = &nr1;
	printf("\n");
	printf("nr1 value %d and is at %p\n", nr1, &nr1);
	printf("nr2 value %d and is at %p\n", nr2, &nr2);
        printf("ptr value %p and is at %p\n", ptr, &ptr);
        printf("The value of the integer pointed to by ptr is %d\n", *ptr);
	return 0;
}
