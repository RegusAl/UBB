#include <stdio.h>
#include <string.h>

int main() {
    int len;
    char string[50], *reversed_ptr, *string_ptr, reversed[50], ch;

    printf("Enter a string: ");
    scanf("%s", string);
    printf("The string is: %s \n", string);

    len = strlen(string);

    reversed_ptr = reversed;
    string_ptr = string+len-1;

    for (int i = 0; i < len ; i++) {
        *reversed_ptr = *string_ptr ;
        reversed_ptr++;
        string_ptr--;
    }
    reversed_ptr--;
  
    printf("The reversed string is: %s \n", reversed);

    return 0;
}