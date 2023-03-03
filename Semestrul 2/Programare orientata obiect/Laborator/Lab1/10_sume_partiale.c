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

void count(float x, int n, float *result) {
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

int main() {
    /*
     * Functia main
     */
    float x;
    float result = 0;

    printf("X = ");
    scanf("%f", &x);


    int n;
    printf("n = ");
    scanf("%d", &n);

    count(x, n, &result);

    printf("Sin(%.2f) = %f\n", x, result);

    return 0;
}