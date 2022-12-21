/* Program demonstrates the use of width and precission for 
 * output for different data types
 */

#include <stdio.h> 
int main() 
{ 
    int int_number=1234567890;
    float flt_number=1234567890.12345;
    char str[] = "string example"; 
// integer examples
    printf("%20d", int_number);
    printf("%-20d", int_number);
    printf("%20.5d", int_number);
// float examples
    printf("%20f", flt_number);
    printf("%-20f", flt_number);
    printf("%20.5f", flt_number);
// string examples
    printf("%20s\n", str); 
    printf("%-20s\n", str); 
    printf("%20.5s\n", str); 
    printf("%-20.5s\n", str); 
    return 0; 
} 

