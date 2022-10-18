#include <stdio.h>

int main() {
	int number1, number2, sum, sum2, sum3;
	number1 = 10;
	number2 = 20;
	
	sum = number1+number2;
	sum2 = ++number1;
	sum3 = number2++;

	printf("Sum values are %d, %d, %d \n", sum, sum2, sum3);
	printf("Numbers are: %3d, %2d\n", number1, number2);

	return 0;
}
