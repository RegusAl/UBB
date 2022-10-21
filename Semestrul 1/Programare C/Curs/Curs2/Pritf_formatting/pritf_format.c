#include <stdio.h>

int main() {
	// Fill spaces
	printf("%-3d", 0);
	printf("%-3d", -1);
	printf("%-3d", 12345);
	printf("%-3d", -12345);
	// Justify
	printf("%+3d", 0);
        printf("%+3d", -1);
        printf("%+3d", 12345);
        printf("%+3d", -12345);
	
	printf("\n");	
	
	return 0;
}
