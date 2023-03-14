#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    int** m;
    FILE* f;
    int i, j, rows, cols;

    f = fopen(argv[1], "r");
    if(f == NULL) {
        perror("Could not open file");
        return 1;
    }
    fscanf(f, "%d %d", &rows, &cols);

    m = (int**)malloc(rows*sizeof(int*));
    for(i=0; i<rows; i++) {
        m[i] = (int*)malloc(cols*sizeof(int));
        for(j=0; j<cols; j++) {
            fscanf(f, "%d", &m[i][j]);
        }
    }
    fclose(f);

    FILE *fd;
    fd = fopen(argv[2], "w");
    if(fd == NULL) {
        perror("Could not open destination file");
        return 1;
    }
    fwrite(&rows, 1 ,sizeof(int), fd);
    fwrite(&cols, 1, sizeof(int), fd);
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            fwrite(&m[i][j], 1, sizeof(int), fd);
        }
    }
    fclose(fd);
    
    for(i = 0; i<rows; i++) {
	free(m[i]);
    }
    free(m);
    return 0;
}
