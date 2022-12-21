#include <stdio.h>
void performtask(int nr1, int nr2, float (*func)(int))
{
        int i;
        for(i=nr1;i<=nr2;i++)
                printf("%d %f\n", i, (*func)(i));
}
float reciprocal(int nr)
{
        return(1.0/nr);
}
float square(int nr)
{
        return(nr*nr);
}
int main()
{
        performtask(1,5,reciprocal);
        printf("\n --------  \n");
        performtask(1,5,square);
        return 0;
}

