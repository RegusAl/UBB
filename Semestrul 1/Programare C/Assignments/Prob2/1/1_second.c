// Write a program to read a set of integers and print the maximum and minimum value.
// (with defined functions)
#include <stdio.h>

// function that reads an array
void readArray(int array[], int size) {
    for(int i = 0; i<size; i++) {
        printf("Enter the number %d: ", i+1);
        scanf("%d", &array[i]);
    }
}

// function that prints the array
void showArray(int array[], int size) {
    for(int i = 0; i<size; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// function that returns the max of the array
int max(int array[], int size) {
    int max = array[0];
    for(int i = 1; i<size; i++) {
        if(array[i]>max)
            max = array[i];
    }
    return max;
}

// function that returns the min of the array
int min(int array[], int size) {
    int min = array[0];
    for(int i = 1; i<size; i++) {
        if(array[i]<min)
            min = array[i];
    }
    return min;
}

// main function
int main() {
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);
    int array[n];
    readArray(array, n);
    showArray(array, n);
    printf("Max number is: %d\n", max(array, n));
    printf("Min number is: %d\n", min(array, n));
    return 0;
}