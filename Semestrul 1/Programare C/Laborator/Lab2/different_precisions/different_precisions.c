#include <stdio.h>

int main() {
	int i;

	float a = 1.f / 81;
	float b = 0;
	for(i = 0; i < 729; ++i)
		b += a;
	printf("%.7g\n", b);
	
	double aa = 1.0 / 81;
	double bb = 0;
	for(i = 0; i < 729; ++i)
		bb += aa;
	printf("%.15g\n", bb);

	return 0;
}
