/* example of using float values */
#include<stdio.h>

int main(){
	float number1, number2;
        double dnumber1, dnumber2;
	
	number1=25.223f;
	printf("Input a float value:");
	scanf(" %f", &number2);
	printf("\nThe values are %6.4f, %6.4f\n",number1, number2);

        dnumber1=25.223;
        printf("Input a double value:");
        scanf(" %lf", &dnumber2);
        printf("\nThe values are %6.4lf, %6.4lf\n",dnumber1, dnumber2);


	return 0;
}
