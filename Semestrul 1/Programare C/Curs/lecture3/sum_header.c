#include<stdio.h>
#include"myheader.h"
 
int main() {
   int num1 = 1, num2 = 9, num3;
   num3 = sum(num1, num2);
   printf("Addition of Two numbers : %d", num3);
   return 0;
}
