#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int rows, cols, i, j;
    int** m;

    if(argc <= 1) {
        fprintf(stderr, "No input file specified");
        exit(1);
    }

    FILE *fd;
    fd = fopen(argv[1], "r");
    if(fd == NULL) {
        perror("Failed to open input file");
        exit(1);
    }

    if(fread(&rows, 1, sizeof(int), fd) <= 0) {
        perror("Could not read the number of rows");
        exit(1);
    }

    if(fread(&cols, 1, sizeof(int), fd) <= 0) {
        perror("Could not read the number of columns");
        exit(1);
    }

    m = (int**)malloc(rows*sizeof(int*));
    for(i=0; i<rows; i++) {
        m[i] = (int*)malloc(cols*sizeof(int));
        fread(m[i], sizeof(int), cols, fd);
	for(j=0; j<cols; j++) {
            printf("%d " , m[i][j]);
        }
        printf("\n");
    }
    fclose(fd);

    for(i = 0; i<rows; i++) {
	free(m[i]);
    }
    free(m);
    return 0;
}
