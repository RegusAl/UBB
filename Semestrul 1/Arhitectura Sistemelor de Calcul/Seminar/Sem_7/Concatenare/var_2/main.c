#include <stdio.h>

// sirul final
char* sir_final;

// procedura definita in asamblare
int concateneaza(char*, char*);

int main(int argc, char* argv[])
{
    char s1[50] = "abc";
    char s2[50] = "ABC";
    int ret = concateneaza(s1, s2);
    printf("Sirul '%s' are %d caractere.", sir_final, ret);
    
    return 0;
}
