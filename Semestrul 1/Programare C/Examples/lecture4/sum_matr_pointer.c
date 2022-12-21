#include <stdio.h>

void arr_sum(int *a, int l, int j)
{
        printf(" processing row - %d\n",j);
        int i, s=0;
        for(i=0;i<l;++i)
        {
                s+=a[i];
                printf("S and a[i]: %d, %d \n", s, a[i]);
        }
        printf("\nSum for row %d is : %d \n",j, s);
}

int main()
{
        int i, j, k, m, n;
        printf("Give 2 integers: ");
        scanf("%d%d",&m,&n);
        int a[m][n];
        for(i=0;i<m;++i)
                for(j=0;j<n;++j)
                {
                        printf("a[%d][%d]=",i,j);
                        scanf("%d",&a[i][j]);
                        printf("\n");
                }
        printf(" - - - function call starts here\n");
        for(k=0;k<m;++k)
                arr_sum(a[k], n, k);
        printf("\nEnd of program\n");
        return 0;
}

