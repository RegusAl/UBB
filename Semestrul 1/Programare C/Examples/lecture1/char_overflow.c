/* example of overflowing
 * note that the program uses char (signed)data type for the first variable 
 * and unsinged char data type for the second variable
 */
#include<stdio.h>

int main(){
    char c1=193;  // first char variable is initialized to -63, as it is greater than 127 and the counter is reset from -128
    unsigned char c2=-160; // second charvariable is initialized to 96 as it is smaller than -128 and the counter continues backwards from 127
    printf("%d  %d",c1,c2); // display the numerical values for the 2 variables
    printf("\n"); // go to next line
    return 0;  // return from main
}

