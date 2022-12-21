#include <stdio.h>
#include <stdlib.h>

int main(){
        int i,j,k,l,d1,d2,d3,d4;
	int sum=0;
        printf("Introduceti cele 4 dimensiuni: \n");
        scanf("%d",&d1);
	scanf("%d",&d2);
	scanf("%d",&d3);
	scanf("%d",&d4);
	int ****a4d = malloc(d1 * sizeof(int ***));
	for(i = 0; i < d1; i++) {
		a4d[i] = malloc(d2 * sizeof(int **));
		for(j = 0; j < d2; j++){
				a4d[i][j]=malloc(d3 * sizeof(int *));
				for(k = 0; k < d3; k++){
				a4d[i][j][k] = malloc(d4 * sizeof(int));
                        }
		}
	}
	printf("Incepe citirea elementelor matricii \n");
        for(i = 0; i < d1; i++)
		for(j = 0; j < d2; j++)
			for(k = 0; k < d3; k++)
				for(l = 0; l < d4; l++){
					printf("elementul a[%d][%d][%d][%d]=",i,j,k,l);
					scanf("%d",&a4d[i][j][k][l]);
					sum+=a4d[i][j][k][l];	
				}
	printf("suma este: %d\n",sum);
	printf("incepem dealocarea\n");	
	for(i = 0; i < d1; i++) {
                for(j = 0; j < d2; j++){
                                for(k = 0; k < d3; k++){
                                free(a4d[i][j][k]);
                        }
			free(a4d[i][j]);
                }
		free(a4d[i]);
        }
	free(a4d);
	printf("program ends\n");
	return 0;
}
