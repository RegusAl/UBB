#include <stdio.h>
#include <string.h>

int main() {

    char greeting[] = "hello world";
    int vowels = 0;
    int nonvowels = 0;
    for(int i = 0; i<strlen(greeting); i++)
    {
        char ch = greeting[i];
        switch (ch)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': 
                vowels++;
                break;
            default:
                nonvowels++;
                break;
        }
    }
    printf("%d, %d", vowels, nonvowels);
    return 0;   
}