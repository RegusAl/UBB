/* the program converts the given weight from kilograms to pounds */

#include<stdio.h>

int main(){

   float kg_val, pounds_val;
   printf("Enter a weight in kg: \n"); // display a message for user
   scanf("%f",&kg_val);                // read the input value as real numbersimple precission
   pounds_val=kg_val*2.2;              // compute the value in pounds
   printf("\n\n%6.2f kilos = %6.2f pounds \n", kg_val, pounds_val);  // display the input and output values
   return 0;                           // return from main

}
