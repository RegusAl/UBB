// Write a program that, given an integer n, computes the first n values from
// Fibonacci Series.
// (without user defined functions)
#include <stdio.h>

int main() {
    int n, x = 0, y = 1, i = 2;
    printf("N = ");
    scanf("%d", &n);
    int array[n];
    array[0] = x;
    array[1] = y;
    while(i<n) {
        int temp = x + y;
        x = y;
        y = temp;
        array[i] = y;
        i++;
    }
    // prints the array
    printf("Fibonacci sequence is: \n");
    for(int i = 0; i<n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}