#include <stdio.h>

int main() {
    int M[10][10];
    int n;
    printf("N = ");
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            scanf("%d", &M[i][j]);
    printf("Matricea este:\n");
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    int max = M[0][0];
    for(int i = 1; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(M[i][j]>max)
                max = M[i][j];
        }
    }
    printf("Elementul maxim din matrice este: %d \n", max);
    return 0;
}