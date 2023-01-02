#include<stdio.h>
#include<stdlib.h>

int main() {

    int **A, **B,**C,i,j,r1,c1,r2,c2;

    // reads the order of matrix A
    printf("\nEnter the Order of the First matrix (A)...\n");
    printf("Number of rows: ");
    scanf("%d",&r1);
    printf("Number of columns: ");
    scanf("%d",&c1);

    // reads the order of matrix B
    printf("\nEnter the Order of the Second matrix (B)...\n");
    printf("Number of rows: ");
    scanf("%d",&r2);
    printf("Number of columns: ");
    scanf("%d",&c2);

    // if number of columns in A != number of rows in B the program stops executing 
    if(c1!=r2) {
        printf("Invalid Order of matrix!!!\n");
        printf("Number of columns in A not equal with number of rows in B \n");
        return 0;
    }

    // memory allocation for A
    A = (int**) malloc(r1*sizeof(int*));

    for(i=0;i<r1;i++)
        A[i]=(int*)malloc(c1*sizeof(int));

    // memory allocation for B
    B = (int**) malloc(r2*sizeof(int*));

    for(i=0;i<r2;i++)
        B[i]=(int*)malloc(c2*sizeof(int));

    C =(int**)calloc(r1,sizeof(int*));

    for(i=0;i<c2;i++)
        C[i]=(int*)calloc(c2,sizeof(int));

    // reads the input for Matrix A
    printf("First Matrix: \n");
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            scanf("%d",&A[i][j]);

    // reads the input for Matrix B
    printf("Second Matrix: \n");
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            scanf("%d",&B[i][j]);

    // prints Matrix A
    printf("\n Matrix A: \n");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }

    // prints Matrix B
    printf("\n Matrix B: \n");
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++)
            printf("%d ",B[i][j]);
        printf("\n");
    }       

    // A * B = C
    for(i=0;i<r1;i++) {
        for(j=0;j<c2;j++) {
            C[i][j]=0;
            for(int k=0;k<c1;k++)
                C[i][j]+= A[i][k]*B[k][j];
        }
        printf("\n");
    }

    // prints Matrix C
    printf("\n Matrix C: \n");
    for(i=0;i<r1;i++) {
        printf("\n");
        for(j=0;j<c2;j++)
            printf("%d\t",C[i][j]);   
    }
    printf("\n");

    return 0;
}
