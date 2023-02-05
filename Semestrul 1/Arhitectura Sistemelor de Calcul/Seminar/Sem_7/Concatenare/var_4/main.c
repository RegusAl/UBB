#include <stdio.h>
#include <string.h>

// procedura definita in asamblare
char* concateneaza(char*, char*);

int main(int argc, char* argv[])
{
    char s1[50] = "abc";
    char s2[50] = "ABC";
    char* sir_final = concateneaza(s1, s2);
    int len = strlen(sir_final);
    printf("Sirul '%s' are %d caractere.", sir_final, len);
    
    return 0;
}
