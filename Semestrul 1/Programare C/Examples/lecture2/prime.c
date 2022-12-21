/* detect if the given value reresents a prime number or not
 * it uses the method for checking all values less than the given number for being a divisor
 */
#include <stdio.h>

int main(){

	int primed, number, flag;

	flag = 1;         // suppose it is prime
	printf("Give a positive integer:");
	scanf("%d", &number);

	for (primed=2; primed < number; primed++)
	{
		if ((number%primed)==0)
		flag = 0; // current primed is a divisor because no remainder, so is not prime
	}
	if(flag == 1)
		printf("\n number %d is prime\n", number);  //all values tested and all have remainder so the number is prime
	else
		printf("\n number %d is not prime\n", number);
	return 0;
}
