#include <stdio.h>

int main() {
	void func(int nr);
	int val = 1;
	printf("%d\n", val);
	func(val);
	printf("%d\n", val);
	func(val);
	return 0;
}

void func(int val) {
	val++;
	printf("%d\n", val);
}
