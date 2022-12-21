/* demonstrates the use of special characters in output
 * note that 'b' changes its meaning by being preceeded with '\' (backspace)
 * the same for '\t' (horisontal tab) and '\n' (new line)
 * it also demonstrates the format specifier for real numbers (float data type)
 *   */


#include <stdio.h>

int
main (void)
{
 printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n" // the output string is writen in the source code on 4 lines
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb\t"
        "cccccccccccccccccccccccccccccc\b"
        "\n");

  printf ("Two plus two is %f\n", 4.0f);
  return 0;
}
