/* addition program
 * it reads two integer numbers and prints their sum
 * */

#include<stdio.h>

int main(){
   int number1, number2, sum;   /* declaration of variables */

   printf("Enter first number\n");  /*  prompt message on console */
   scanf("%d", &number1); /* read an integer */
   printf("Enter another number\n"); /* prompt again a message */
   scanf("%d", &number2); /* read another integer */
   sum=number1+number2;   /* assignment of sum */
   printf("Sum is %d\n", sum); /* the sum value is printed */

   return 0; /* return from main */

}
