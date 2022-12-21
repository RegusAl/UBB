#include <stdio.h>

char strA[80] = "A string to be used for demonstration purposes";
char strB[80];

int main(void)
{

    char *pA;     /* a pointer to type character */
    char *pB;     /* another pointer to type character */
    puts(strA);   
    pA = strA;    /* point pA at string A */
    puts(pA);     
    pB = strB;    /* point pB at string B */
    putchar('\n');       
    while(*pA != '\0')   /* line A  */
    {
        *pB++ = *pA++;   /* line B  */
    }
    *pB = '\0';          /* line C  */
    puts(strB);          
    return 0;
}

