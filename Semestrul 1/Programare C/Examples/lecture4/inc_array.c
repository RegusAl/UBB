#include<stdio.h>

void inc_array(int a[ ], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		a[i]++;
	}
}

int main()
{
	int test[3]={1,2,3};
	int ary[4]={1,2,3,4};
	int i;
	inc_array(test,3);
	for(i=0;i<3;i++)
		printf("%d\n",test[i]);
	inc_array(ary,4);
	for(i=0;i<4;i++)
		printf("%d\n",ary[i]);
	return 0;
}
