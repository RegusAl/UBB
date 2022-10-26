// 3.  Write a program that computes out the largest and smallest values of 5 numbers
// read from the input.

#include <stdio.h>

int main() {
    int max, min;
    int i = 1, x;
    printf("Enter number %d: ", i);
    scanf("%d", &x);
    max = x;
    min = x;
    for(int i = 2; i<=5; i++) {
        int x;
        printf("Enter number %d: ", i);
        scanf("%d", &x);
        if (x < min)
            min = x;
        if (x > max)
            max = x;
    }
    printf("Max: %d, Min: %d \n", max, min);
    return 0;
}