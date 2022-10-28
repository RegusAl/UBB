// 5. Knowing that we have coins of 1, 2 and 5 units, determine the minimum number of
// coins to pay a given amount.

#include <stdio.h>

int main() {
    int amount, coins = 0;
    printf("Enter the amount to pay:");
    scanf("%d", &amount);
    int aux = amount;
    while(amount) {
        if (amount - 5 >= 0) {
            coins++;
            amount -= 5;
        } else if (amount - 2 >= 0) {
            coins++;
            amount -= 2;
        } else {
            coins++;
            amount -= 1;
        }
    }
    printf("The minimum number of coins to pay %d is %d \n", aux, coins);
    return 0;
}