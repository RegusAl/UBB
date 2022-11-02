#include<stdio.h>
void f1(void);
void f2(void);
int var1=1;

int main(){
        printf("Declaration and/or definition");
        var1=2;
        printf("var1 = %d\n",var1);
        f1();
        f2();
        printf("var1 = %d\n",var1);
        return 0;
}
