// Tipareste un numar precizat de sume partiale din dezvoltarea
//    sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
#include <stdio.h>

int factorial(int n) {
    // functia factorial ce primeste ca parametru un numar n si calculeaza factorialul sau
    // param: n
    // tupe: int
    // return: factorialul lui n
    if(n == 1 || n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int power(float n, int p) {
    /*  functia power ce primeste ca parametru un numar si puterea la care se ridica
     *  param: n - numarul ce trebuie ridicat la puterea p
     *  param: p - puterea la care se ridica numarul n
     *  return : n^p
     */
    if(p == 1) {
        return n;
    } else if (p == 0) {
        return 1;
    }else {
        return n * power(n, p-1);
    }
}

void suma(float x, int n, float *result) {
    /*
     * Functia count ce calculeaza fiecare suma partiala
     * param x: numarul x a carui suma se calculeaza
     * param n: numarul de sume
     * param result: rezultatul sumei partiale
     */
    int count, sign = 1;

    for(count = 1; count < n*2; count += 2)
    {
        double pwr = power(x, count);
        double fact = factorial(count);
        *result  += sign * (pwr/fact);
        printf("Suma partiala de ordin %d este: %f\n", count/2 + 1, *result);
        sign *= -1;
    }
}

// Determina primele 10 numere naturale strict mai mari ca 2, care au
//    proprietatea ca toate numerele naturale strict mai mici decat ele
//    si care sunt prime cu ele sunt numere prime.
int prim(int x) {
    /*
     * Functia determina daca x este prim
     * param x: numarul ce este verificat
     * return : 1 - daca este prim, 0 - daca nu este prim
     */
    for(int d = 2; d<x; d++) {
        if(x%d==0) {
            return 0;
        }
    }
    return 1;
}

int prim_intre_ele(int x, int y) {
    /*
     * determina daca x si y au divizori comuni
     */
    if(x == 0)
        return y;
    if(y == 0)
        return x;
    while(x != y) {
        if(x > y)
            x = x - y;
        else
            y = y - x;
    }
    return x;
}

void numere_10() {
    int x = 3, i = 0;
    while(i < 8) {
        int ok = 1;
        for(int y = x-1; y >= 1; y--) {
            if(prim_intre_ele(x, y)==1) {
                if(prim(y)==0) {
                    ok = 0;
                }

            }
        }
        if(ok == 1) {
            i++;
            printf("%d ", x);
        }
        x++;
    }
    printf("\n");
}

int main() {
    /*
     * Functia main
     */
    char option;
    printf("Optiune (1 / 2): ");
    scanf("%d", &option);
    float x, result = 0;
    while (option)
     {
         if(option==1) {

             printf("X = ");
             scanf("%f", &x);

             int n;
             printf("n = ");
             scanf("%d", &n);

             result = 0;
             suma(x, n, &result);
             printf("Sin(%.2f) = %f\n", x, result);

             printf("Optiune (1 / 2): ");
             scanf("%d", &option);
         }
         if(option==2) {
             numere_10();

             printf("Optiune (1 / 2): ");
             scanf("%d", &option);
         }
         if(option==0) {
             printf("Optiunea nu exista!");
         }
     }
    return 0;
}