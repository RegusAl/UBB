// 7. Being given the values of the diagonals of a diamond shape (romb), compute the
// area and perimeter of the diamond shape.

#include <stdio.h>
#include <math.h>

int main() {
    int diagonal1, diagonal2;
    printf("Enter the length of the diagonals of a diamond shape\n");
    printf("Diagonal 1:");
    scanf("%d", &diagonal1);
    printf("Diagonal 2:");
    scanf("%d", &diagonal2);
    // area = (d1 * d2) / 2
    float area = (diagonal1 * diagonal2) / 2;
    printf("The area of the rhombus is %.2f\n", area);
    // perimeter = 4 * l
    double l = (sqrt(diagonal1 * diagonal1 + diagonal2 * diagonal2))/2; 
    //printf("%lf", l);
    double perimeter = l * 4;
    printf("The perimeter of the rombus is %.2lf\n", perimeter);
    return 0;
}