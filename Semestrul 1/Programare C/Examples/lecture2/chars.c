/* demontrates the input and output for a char
 * note that the character is stored as an integer (int, not char)
 * and is read and printed with %c
 * */

#include<stdio.h>
   int main(){
   int c;  // declare the variable that will store the value inserted
   scanf(" %c",&c); // read the character
   printf("%c\n",c); // print the character

/* alternative way of reading writing characters
 * c=getchar();
   putchar(c);
*/
   return 0; // return from main

}
