//
// Created by albert on 03/03/23.
//
#include <stdio.h>

int main() {
    printf("Hello!\n");
    int n, s = 0;
    printf("N = ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int numar;
        printf("numar %d: ", i+1);
        scanf("%d", &numar);
        s += numar;
    }
    printf("Suma numerelor este: %d\n", s);
    return 0;
}