// 2. Read two integers and compute their sum, average and sum of the squares of the
// numbers.

#include <stdio.h>

int main() {
    int nr1, nr2;
    printf("First number is: ");
    scanf("%d", &nr1);
    printf("Second number is: ");
    scanf("%d", &nr2);
    printf("The numbers are: %d, %d \n", nr1, nr2);

    // Sum of the two numbers
    int sum = 0;
    sum = nr1 + nr2;
    printf("The sum of the two numbers is: %d \n", sum);

    // Average of the two numbers
    float avg = 0.;
    avg = (float) sum / 2;
    printf("The average of the two numbers is: %f \n", avg);

    // Sum of the squares of the two numbers
    int sumOfSquares = 0;
    sumOfSquares = (nr1 * nr1) + (nr2 * nr2);
    printf("The sum of the squares is: %d \n", sumOfSquares);

    return 0;
}