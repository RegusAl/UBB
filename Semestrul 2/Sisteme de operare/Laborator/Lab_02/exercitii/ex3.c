#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
	FILE *fd = fopen("matrix.txt", "r");
	if(fd == NULL) {
		perror("Error");
		exit("EXIT_FAILURE");
	}
	int  matrix[3][4];
	int i = 0;
	int j = 0;
	char c = '\0';
	while((c = fgetc(fd)) != EOF) {
		if(!isspace(c)) {
			matrix[i][j] = c - 48;
			j++;
			if(j == 4) {
				i++;
				j = 0;
			}
		}
		if(i == 3)
			break;
	}

	for(int i = 0; i<3; i++) {
		for(int j = 0; j<4; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
