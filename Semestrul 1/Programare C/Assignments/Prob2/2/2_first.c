// Use Eratosthenes's sieve to determine all prime numbers less than a given integer.
// (without any user defined functions)
#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int array[n+1];
    // set all the elements 1 (True) 
    for(int i = 2; i<=n; i++) {
        array[i] = 1;
    }
    for(int i = 2; i*i<=n; i++) {
        if(array[i]==1) {
            int x = 0;
            while(i*i+i*x<=n) {
                array[i*i + i*x] = 0;
                x++;
            }
        }
    }
    printf("All the prime numbers less than %d are: ", n);
    for(int i = 2; i<=n; i++) {
        if(array[i]==1)
            printf("%d  ", i);
    }
    printf("\n");
    return 0;
}