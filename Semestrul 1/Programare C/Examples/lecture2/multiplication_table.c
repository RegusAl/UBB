/* print a multiplication table */
#include<stdio.h>
int main(){
   int type, start, end, j;
   printf("Type of table?");
   scanf("%d",&type);
   printf("start of table?");
   scanf("%d",&start);
   printf("end of table?");
   scanf("%d",&end);
   for(j=start;j<=end;j++)
      printf("\n%2d x %2d = %3d", j, type, j * type);
   printf("\nEnd of program\n");
   return 0;
}
