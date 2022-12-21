/* detects if a number is a perfect square or not
 * uses the method of checcking if its square root is a integer value or not
 */

#include <stdio.h>
#include <math.h>  // library needed for sqrt function; compilation should be done with "-lm" option

int main(){
    int number;
    printf ("\n Introduce an integer: ");  // display a message
    scanf ("%d", &number);                 // read a integer value

    if (sqrt(number)==floor(sqrt(number))) // check if its square root is integer
	    printf ("\n The integer is a perfect square \n");
    else
	    printf ("\n The integer is not a perfect square \n");

    return 0;

}
