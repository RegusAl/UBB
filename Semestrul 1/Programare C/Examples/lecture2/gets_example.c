/* gets() example */
#include <stdio.h> 
 
int main() 
{ 
    char sir[20]; 
  
    printf("Introduceti un string: "); 
    gets(sir); 
    printf("Sirul este: %s\n", sir); 
  
    return 0; 
} 
