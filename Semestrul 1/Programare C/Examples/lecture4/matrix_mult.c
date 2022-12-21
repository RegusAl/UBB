#include<stdio.h>
#define MAX 10

int main()
{
	int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];
	int m1_nr1, m1_nr2, m2_nr1, m2_nr2, ind_col1, ind_row1, ind_col2, ind_row2, sum=0;
	
	do{
		printf("Enter matrix1 dimensions (between 2 and %d): ",MAX);
		scanf("%d %d",&m1_nr1, &m1_nr2);
	}while(m1_nr1>MAX||m1_nr2>MAX||m1_nr1<=1||m1_nr2<=1);

        do{
                printf("Enter matrix2 dimensions (between 2 and %d): ",MAX);
                scanf("%d %d",&m2_nr1, &m2_nr2);
        }while(m2_nr1>MAX||m2_nr2>MAX||m2_nr1<=1||m2_nr2<=1);


	if(m1_nr2!=m2_nr1)
	{
		printf("Multiplication not possible!\n");
		return -1;
	}	

	printf("\n\nEnter elements of the first matrix\n");
	for(ind_row1=0;ind_row1<m1_nr1;ind_row1++)
		for(ind_col1=0;ind_col1<m1_nr2;ind_col1++)
		{
			printf("Enter value for element matrix1[%d][%d]: ",ind_row1, ind_col1);
			scanf("%d",&matrix1[ind_row1][ind_col1]);
			printf("\n");
		}
        printf("\n\nEnter elements of the second matrix\n");
        for(ind_row2=0;ind_row2<m2_nr1;ind_row2++)
                for(ind_col2=0;ind_col2<m2_nr2;ind_col2++)
                {
                        printf("Enter value for element matrix2[%d][%d]: ",ind_row2, ind_col2);
                        scanf("%d",&matrix2[ind_row2][ind_col2]);
                        printf("\n");
                }

	for( ind_row1 = 0 ; ind_row1 < m1_nr1 ; ind_row1++ )
	{
      		for ( ind_col1 = 0 ; ind_col1 < m2_nr2 ; ind_col1++ )
      		{	
        		for ( ind_row2 = 0 ; ind_row2 < m1_nr2 ; ind_row2++ )
        		{
          			sum = sum + matrix1[ind_row1][ind_row2]*matrix2[ind_row2][ind_col1];
        		}
 
        		result[ind_row1][ind_col1] = sum;
        		sum = 0;
      		}
    	}

        printf("\n\nElements of the product matrix:\n\n");
	for(ind_row1=0;ind_row1<m1_nr1;ind_row1++)
        {
		for(ind_col1=0;ind_col1<m2_nr2;ind_col1++)
                        printf("%d ",result[ind_row1][ind_col1]);
             
	        printf("\n");
        }       
		
	return 0;
}
