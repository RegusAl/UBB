/* example program for passing of an array to a function */
#include <stdio.h>
#include <stdlib.h>

int array_limit;  // used to read the number of elements in the array

int max_val( int [] );          /*function prototype, not necessary if main is after function implementation */ 

int  max_val( int array[array_limit] )
{
	int  max, i;
	
	max = array[0];
	for( i = 0; i < array_limit; ++i )
		if( array[i] > max )
			max = array[i];
	
	return max;
}
	
int main()
{
	int array_val[100], i, max;
	
	printf("Enter length: ");
	scanf("%d",&array_limit);

	printf("\nEnter %d numbers\n",array_limit);
	for( i = 0; i < array_limit; ++i )
		scanf("%d", &array_val[i] );
		
	max = max_val(array_val);	// call function passing array as argument
	printf("\nMax value is %d\n", max );

	return 0;
}
