#include <stdio.h>

void mysort(int a[ ],int size)
{
  int i,j,x;
  for(i=0; i<size; i++)
  {
    for(j=i; j>0; j--)
    {
      if(a[ j ] < a[ j-1])
      {  /* Change the order of a[ j ] and a[ j-1] */
          x=a[ j ];a[ j ]=a[ j-1]; a[j-1]=x;
      }
    }
  }
}

int main()
{
	int i;
	int tab[10] = {3,6,3,5,9,2,4,5,6,0};
	for(i=0;i<10;i++)
		printf("%d ",tab[i]);

	printf("\n");
	mysort(tab,10);
	for(i=0;i<10;i++)
		printf("%d ",tab[i]);

	printf("\n");
	return 0;
}
