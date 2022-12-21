/* addition program
 * it uses 2 integer numbers and prints their sum
 * also, it uses pre and post increment to demonstrate their use
 * */

#include<stdio.h>

int main(){
   int number1, number2, sum, sum2, sum3;   /* declaration of variables */
 
   // initialize the 2 integers
   number1=10;
   number2=20;
   
   sum=number1+number2;   /* assignment of sum */

   
   sum2 = ++number1;     /* first, number is incremented then assigne to sum2 */ 
   sum3 = number2++;     /* first, number is assigned to sum2 then incremented*/ 

   printf("Sum values are %d,  %d,  %d\n", sum, sum2, sum3); /* the sum values are printed */
   printf("Numbers are :%3d,%2d\n", number1, number2);  /* numbers are printed */

   return 0; /* return from main (to operating system)*/

}
