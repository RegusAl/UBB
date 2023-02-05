#include <stdio.h>

// procedura definita in asamblare
int concateneaza(char*, char*, char*);

int main(int argc, char* argv[])
{
    char s1[50] = "abc";                            // primul sir
    char s2[50] = "ABC";                            // al doilea sir
    char sir_final[100] = "";                       // sirul rezultat prin concatenare
    int ret = concateneaza(s1, s2, sir_final);
    printf("Sirul '%s' are %d caractere.", sir_final, ret);
    
    return 0;
}
