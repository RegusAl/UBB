// Cauta binar intr-un sir ordonat o valoare v data la linia de comanda  
#include <stdio.h>
#include<stdlib.h>
int main (int argc, char *argv[]) {
    int sir[] = {1,2,4,5,7,8,9};
    int m, s, d, v, n;
    v = atoi(argv[1]);
    int g = 0;
    n = sizeof(sir) / sizeof(int);
    printf("Se cauta %d in sirul urmator:\n", v);
    for (s=0; s<n; printf("sir[%d]=%d ",s, sir[s]), s++);
    printf("\n");
    for ( s = 0, d = n-1; s <= d ; ) {
        m = (s + d) / 2;
        if (sir[m] == v) {g=1;break;}
        if (sir[m] <= v) s = m + 1; else d = m - 1;
    }
    if (g == 0) 
        printf("NU! %d ar trebui sa fie aproape de pozitia %d\n", v, m);
    else
        printf("Da, %d este pe pozitia %d in sir\n", v, m);
    return 0;
}
