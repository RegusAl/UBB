#include <stdio.h>

int main(){
	struct point{
		int p1;
		int p2;
	}pt;
	pt = (struct point) { 100, 200 };
//	pt = (struct point) { .p1 = 100, .p2 = 200 };

	printf("Values: %d, %d\n",pt.p1, pt.p2);
	return 0;
}
