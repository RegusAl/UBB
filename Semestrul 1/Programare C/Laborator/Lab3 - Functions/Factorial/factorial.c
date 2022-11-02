#include <stdio.h>

int main() {
    int factorial(int n), i;
    printf("Value of n and n!:\n");
    for(i = 0; i<=5; i++) {
        printf("%2d! = %4d\n", i, factorial(i));
    }
    return 0;
}

int factorial(int x) {
    int p;
    if(x<0)
        return 0;
    for(p = 1; x>0; x--)
        p = p*x;
    return p;
}