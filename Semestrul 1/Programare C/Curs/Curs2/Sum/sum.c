#include <stdio.h>

int main() {
	int number1, number2, sum = 0;
	printf("Enter the first number:");
	scanf("%d", &number1);
	printf("Enter the second number:");
	scanf("%d", &number2);
	sum = number1 + number2;
	printf("Sum is %d\n", sum);
	return 0;
}
