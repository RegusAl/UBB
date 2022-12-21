//Counts the number of sentences in file, separated by .?!

#include <stdio.h>
#include <string.h>
int main (int argc, char* argv[]) {
    char linie[1000], *p, *q;
    int propozitii = 0;
    FILE* f = fopen(argv[1], "r");
    for (;; ) {
        p = fgets(linie, 1000, f);
        if (p == NULL) break;
        for (p = linie, q = NULL;; ) {
            q = strchr(p, '.');
            if (q == NULL) break;
            propozitii++;
            p = q + 1;
        }
        for (p = linie, q = NULL;; ) {
            q = strchr(p, '!');
            if (q == NULL) break;
            propozitii++;
            p = q + 1;
        }
        for (p = linie, q = NULL;; ) {
            q = strchr(p, '?');
            if (q == NULL) break;
            propozitii++;
            p = q + 1;
        }
    }
    fclose(f);
    printf("In \"%s\" are %d sentences\n", argv[1], propozitii);
    return 0;
}

