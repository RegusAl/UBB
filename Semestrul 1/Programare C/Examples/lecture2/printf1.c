/* demonstrates the use of special characters in output
 * note that 'b' changes its meaning by being preceeded with '\'
 */

#include <stdio.h>

int main()
{

	printf("space \bnon-space\n"); // the output is in accordance with \b (backspace)
	return(0);

}
