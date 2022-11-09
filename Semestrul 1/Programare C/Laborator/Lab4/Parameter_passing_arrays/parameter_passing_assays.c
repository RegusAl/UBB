#include <stdio.h>

int main() {
	void func(int nr[], int max);
	int cnt, num[3];
	for(cnt = 0; cnt<3; cnt++)
		num[cnt] = cnt;
	func(num, 3);
	for(cnt = 0; cnt<3; cnt++)
		printf("%d ", num[cnt]);
	return 0;
}

void func(int num[], int max) {
	int i;
	for(i = 0; i<max; i++)	
		num[i] = num[i]+1;
}
