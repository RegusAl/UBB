#include <stdio.h>

int nr1, nr2;
int *ptr;

int main()
{
    nr1 = 1;
    nr2 = 2;
    ptr = &nr1;
    printf("\n");
    printf("nr1 has the value %d and is stored at %p\n", nr1, &nr1);
    printf("nr2 has the value %d and is stored at %p\n", nr2, &nr2);
    printf("ptr has the value %p and is stored at %p\n", ptr, &ptr);
    printf("The value of the integer pointed to by ptr is %d\n", *ptr);

    return 0;
}
