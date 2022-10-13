#include <stdio.h>

int main()
{
	printf("Hello World!\n");
	printf("Enter your name:");
	char firstName[30];
	scanf("%s", firstName);
	printf("Hello, %s ", firstName);
	return 0;
}
