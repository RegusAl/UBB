#include <stdio.h>
/*  C program to print the average of n numbers and each difference to the average. */

int main()
{
  int number[100], count;
  float sum, average;
  int n=0; // we guard against an undefined value for n
  
  do{
     printf("\nGive the value for n (1-100)");
	 scanf("%d", &n);
  } while ((n<1)||(n>100));
  
  sum=0;
  for(count=0;count<n;count++){
     scanf("%d",&number[count]);
	 sum+=number[count];
  }
  average=sum/n;
  printf("\nAverage of the %d numbers is %7.2f\n",n, average);
  /* In order to print the difference between each element and
  the average, we need to iterate through the array */
  for(count=0;count<n;count++)
     printf("For the element %d, the difference between %d and average %7.2f is: %7.2f\n", count, number[count], average, number[count]-average);
  
  return 0;
} /* end of main */
