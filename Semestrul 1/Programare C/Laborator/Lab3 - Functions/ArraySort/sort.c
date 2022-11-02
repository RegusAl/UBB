#include <stdio.h>

int main() {
    int n, arr[100];
    printf("N = ");
    scanf("%d", &n);
    printf("Citeste cele %d elemente\n", n);
    for(int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    //int arr[] = {79, 1, 4, 23, 56, 12, 78, 9, 3, 0}, size = 10;
    void sort(int arr[], int n);
    sort(arr, n);
    for(int i = 0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    return 0;
}

void sort(int arr[], int size) {
    for(int i = 0; i<size-1; i++) {
        for(int j = i+1; j<size; j++) {
            if(arr[i]>arr[j]) {
                int k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }
}