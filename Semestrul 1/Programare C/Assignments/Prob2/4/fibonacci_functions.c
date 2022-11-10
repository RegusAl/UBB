// Write a program that, given an integer n, computes the first n values from
// Fibonacci Series.
// (with user defined functions)
#include <stdio.h>

// fibonacci function
void fibonacci(int array[], int size)  {
    array[0] = 0;
    array[1] = 1;
    int i = 2;
    while(i<size) {
        array[i] = array[i-1] + array[i-2];
        i++;
    }
}

// function that prints the array
void printArray(int array[], int size) {
    printf("The first %d values of fibonacci sequence are: ", size);
    for(int i = 0; i<size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("N = ");
    scanf("%d", &n);
    int array[n];
    fibonacci(array, n);
    printArray(array, n);
    return 0;
}