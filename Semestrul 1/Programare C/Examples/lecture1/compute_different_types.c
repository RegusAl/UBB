/* demonstrates the use of numeric data type with different precisions
 * the "same" computations are done for both data types (float and double)
 * the results obtained are different
 */

#include <stdio.h>

int main()
{
    int i;

    float a = 1.f / 81;
    float b = 0;
    for (i = 0; i < 729; ++ i)
            b += a;
    printf("%.7g\n", b);   // prints 9.000023


    double aa = 1.0 / 81;
    double bb = 0;
    for ( i = 0; i < 729; ++ i)
            bb += aa;
    printf("%.15g\n", bb);   // prints 8.99999999999996

    return 0;
}

