// Write a program to read a set of integers and print the maximum and minimum value.
// (without any user defined functions)
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i<n; i++) {
        printf("Enter the number %d: ", i+1);
        scanf("%d", &array[i]);
    }
    printf("\nThe array is: \n");
    for(int i = 0; i<n; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n\n");
    int max = array[0], min = array[0];
    for(int i = 1; i<n; i++) {
        if(array[i]<min)
            min = array[i];
        else if(array[i]>max)
            max = array[i];
    }
    printf("The max is %d\n", max);
    printf("The min is %d\n", min);
    return 0;
}