/* demontrates the use of real data type with double precision
 * for input and out
 */

#include <stdio.h>
int main(){
	double d;
	scanf("%lf", &d);  // read a double precision value (lf sppecifier)
	printf("%16.14lf\n", d); // display a double precision value specifying the number of characters for the output
	return 0;
}
