/*
 Decupeaza un fisier "mare" in fisiere parti: 000001, 000002, 000003 ...
 Decuparea se realizeaza citind blocuri de octeti consecutivi.
 A se confrunta cu executia programului similar split1.c
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXBUFFER 8192
int main (int argc, char *argv[]) {
    long BUCATA, LUNGIME, lo;
    int in, out, nrf, c, ib, rb;
    struct stat stare;
    char nume[16], *stNume, b[MAXBUFFER];
    BUCATA = 1000;
    if (argc > 2) BUCATA = atol(argv[2]);
    stat(argv[1], &stare);
    LUNGIME = stare.st_size;
    printf("Start Split. \"%s\": %ld\n", argv[1], LUNGIME);
    in = open(argv[1], O_RDONLY);
    for ( lo=0, nrf=0, rb=0, ib=0;; ) {
printf("lo: %d, nrf: %d, rb: %d, ib: %d\n",lo, nrf, rb, ib);
        if (rb == 0) {
            rb = read(in, b, MAXBUFFER); 
            if (rb == 0) break;//EOF
            ib = 0;
        }
        for (;; ) { // Scrie in out continutul bufferului
printf("lo: %d, nrf: %d, rb: %d, ib: %d\n",lo, nrf, rb, ib);
            if (lo % BUCATA == 0) { // Trebuie inceputa o noua bucata
                if (nrf > 0) { // Inainte de incepere, se inchide out curent
                    printf("%ld depus in \"%s\", ramas in \"%s\"  %ld\n", BUCATA, stNume, argv[1], LUNGIME-BUCATA*nrf);
                    close(out);
                }
                nrf++;
                sprintf(nume, "00000%d", nrf);
                stNume = nume + strlen(nume) - 5; // Nume de fisier de 5 cifre
                out = open(stNume, O_CREAT|O_TRUNC|O_WRONLY, 00777);
printf("lo: %d, nrf: %d, rb: %d, ib: %d\n",lo, nrf, rb, ib);
            }
printf("lo: %d, nrf: %d, rb: %d, ib: %d\n",lo, nrf, rb, ib);
            c = BUCATA - lo % BUCATA; // Ramas de pus in out curent
            if (c > rb) c = rb;
printf("lo: %d, nrf: %d, rb: %d, ib: %d\n",lo, nrf, rb, ib);
            write(out, &b[ib], c);
            ib += c;
            rb -= c;
            lo += c;
printf("lo: %d, nrf: %d, rb: %d, ib: %d\n",lo, nrf, rb, ib);
            if (rb == 0) break;// Terminat de golit continutul bufferului
        }
    }
    printf("%ld depus in \"%s\". Stop Split\n", LUNGIME % BUCATA, stNume);
    close(out);
    close(in);
    return 0;
}

