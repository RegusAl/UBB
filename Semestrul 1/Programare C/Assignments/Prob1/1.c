// 1. Write a program to read a number of units of length (a float) and print out the
// area of a circle with that radius. Assume that the value of pi is 3.14159. After
// that, change the type to double and compare the results.

#include <stdio.h>

int main() {
    float number;
    const float pi = 3.14159;
    printf("Insert a number of units of length\n");
    scanf("%f", &number);
    printf("Your number is: %f\n", number);
    //  A=π*r^2
    float radius = number / 2;
    float Area = pi * radius * radius;
    printf("(float) Area of the circle with the length of %f is: %f \n", number, Area);

    double Area_double = (double)Area;
    printf("(double) Area of the circle with the length of %f is: %lf \n", number, Area_double);
    return 0;
}