/* computes the greatest common divisor */
#include<stdio.h>
int main(){
   int m, n, r;
   do{
     printf("\nEnter two positive integers:");
     scanf("%d %d",&m, &n);
   }while(m<=0||n<=0);
   do{
     r=m%n;
     m=n;
     n=r;
   }while(r>0);
   printf("result is %d\n",m);
   return 0;
}
