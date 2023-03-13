#include <stdio.h>

int main() {
	int n, s = 0;
	printf("N = ");
	scanf("%d", &n);	
	int x, max = -9999, min = 9999;
	for(int i = 0; i<n; i++) {
		printf("x[%d] = ", i+1);
		scanf("%d", &x);
		s += x;
		if(x < min) {
			min = x;
		}
		if(x > max) {
			max = x;
		}
	}
	printf("Media aritmetica: %d\n", s/n);
	printf("MAX = %d\n", max);
	printf("MIN = %d\n", min);
	return 0;
}
