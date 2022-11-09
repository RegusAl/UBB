// Use Eratosthenes's sieve to determine all prime numbers less than a given integer.
// (with defined functions)
#include <stdio.h>

// initializes the Array with 1 (True)
void initializeArrayTrue(int array[], int size) {
    for(int i = 2; i<=size; i++) {
        array[i] = 1;
    }
}

// the sieve of Eratosthenes
void Eratosthenes(int array[], int size) {
    for(int i = 2; i*i<=size; i++) {
        if(array[i]==1) {
            int x = 0;
            while(i*i+x*i<=size) {
                array[i*i+i*x] = 0;
                x++;
            }
        }
    }
}

// function that prints the prime numbers
void printPrimeNumbers(int array[], int size) {
    for(int i = 2; i<=size; i++) {
        if(array[i]==1)
            printf("%d ", i);
    }
}

// main function
int main() {
    int n;
    printf("N = ");
    scanf("%d", &n);
    int array[n+1];
    initializeArrayTrue(array, n);
    Eratosthenes(array, n);
    printf("The prime numbers less than %d are: ", n);
    printPrimeNumbers(array, n);
    printf("\n");
    return 0;
}