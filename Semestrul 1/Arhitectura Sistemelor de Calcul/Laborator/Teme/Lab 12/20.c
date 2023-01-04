// Se citeste din fisierul numere.txt un sir de numere. Sa se determine sirul destinatie D care contine numerele din sirul initial cu valorile dublate dar in ordine inversa din sirul initial. Sa se afiseze sirul obtinut pe ecran.
//   Ex: s: 12, 2, 4, 5, 0, 7 => 14, 0, 10, 8, 4, 24

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 101

void dublare(int v[], int n);

void inversare(int v[], int n)
{
    int i, aux;
    for (i = 0;i < n / 2;i++)
    {
        aux = v[i]; v[i] = v[n-i-1]; v[n-i-1] = aux;
    }
}

void afisare(int v[], int n)
{
    int i;
    for (i = 0;i < n;i++)
        printf("%d ", v[i]);
}

int main()
{
    FILE* fp;
    int sir[MAX],i=0,n=0,cnt;
    char c,buff[MAX];

    fp = fopen("numere.txt", "r"); //deschidem fisierul
    if (fp == NULL) //daca apare eroare in deschiderea fisierului
    {
        printf("Eroare citire fisier");
        return -1;
    }
    

    //citim din fisier si le introducem in vector
    do {
        for (cnt = 0;(c = fgetc(fp)) != '\n' && c!=' ' && c != EOF;cnt++)
            buff[cnt] = c;
 
        buff[cnt] = '\0';
        sir[i] = atoi(buff);
        i++;
        cnt = 0;
        if (feof(fp))
            break;
    } while (1);
    
    n = i;
    inversare(sir, n);
    dublare(sir, n);
    printf("Sirul rezultat: \n");
    afisare(sir, n);
    fclose(fp);
    return 0;
}