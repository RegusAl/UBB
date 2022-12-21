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
        if (rb == 0) {
            rb = read(in, b, MAXBUFFER); 
            if (rb == 0) break;//EOF
            ib = 0;
        }
        for (;; ) { // Write out the buffer content
            if (lo % BUCATA == 0) { // new chunk must be started
                if (nrf > 0) { // Before starting with new one, current file has to be closed
                    printf("%ld written to \"%s\", left in \"%s\"  %ld\n", BUCATA, stNume, argv[1], LUNGIME-BUCATA*nrf);
                    close(out);
                }
                nrf++;
                sprintf(nume, "00000%d", nrf);
                stNume = nume + strlen(nume) - 5; // File name has length of 5 digits
                out = open(stNume, O_CREAT|O_TRUNC|O_WRONLY, 00777);
            }
            c = BUCATA - lo % BUCATA; // Left to be written in current out
            if (c > rb) c = rb;
            write(out, &b[ib], c);
            ib += c;
            rb -= c;
            lo += c;
            if (rb == 0) break;// Buffer is empty
        }
    }
    printf("%ld written to \"%s\". Stop Split\n", LUNGIME % BUCATA, stNume);
    close(out);
    close(in);
    return 0;
}

