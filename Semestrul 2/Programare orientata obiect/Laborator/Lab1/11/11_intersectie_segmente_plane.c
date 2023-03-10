// 11. Determina intersectia a doua segmente plane (date prin coordonatele lor carteziene).
#include <stdio.h>
#include <stdlib.h>

struct punct {
    float x, y;
} A, B, C, D;

int main() {

    printf("A(x) = ");
    scanf("%f", &A.x);
    printf("A(y) = ");
    scanf("%f", &A.y);
    printf("B(x) = ");
    scanf("%f", &B.x);
    printf("B(y) = ");
    scanf("%f", &B.y);
    printf("C(x) = ");
    scanf("%f", &C.x);
    printf("C(y) = ");
    scanf("%f", &C.y);
    printf("D(x) = ");
    scanf("%f", &D.x);
    printf("D(y) = ");
    scanf("%f", &D.y);

    // Mx + Ny + c = 0
    // M - panta
    // N - ordonata la origine
    // ecutaia AB = x * (B.y - A.y) + y * (A.x - B.x) + A.y * B.x - A.x * B.y = 0
    // ecutaia CD = x * (D.y - C.y) + y * (C.x - D.x) + C.y * D.x - C.x * D.y = 0

    // ecuatia lui AB
    float M1 = B.y - A.y;
    float N1 = A.x - B.x;
    float C1 = A.y * B.x - A.x * B.y;

    // ecuatia lui CD
    float M2 = D.y - C.y;
    float N2 = C.x - D.x;
    float C2 = C.y * D.x - C.x * D.y;

    if (A.x == C.x && A.y == C.y)
        printf("Punctul de intersectie are coordonatele: (%f, %f).", A.x, A.y);
    else if (B.x == D.x && B.y == D.y)
        printf("Punctul de intersectie are coordonatele: (%f, %f).", B.x, B.y);
    else {
        float X, Y;
        if (N1 != 0) {
            X = (N1 * C2 - C1) / (N2 * M1 - N1 * M2);
            Y = -(M1 * X + C1) / N1;
        } else {
            X = -C1 / M1;
            Y = -(C2 + M2 * X) / N2;
        }
        printf("%f, %f\n", X, Y);
        if ((abs(B.x - A.x) >= X && abs(B.y - A.y) >= Y) && (abs(D.x - C.y) >= X && abs(D.y - C.y) >= Y))
            printf("Punctul de intersectie are coordonatele: (%f, %f).", X, Y);
        else
            printf("Segmentele nu se intersecteaza!");
    }
    return 0;
}