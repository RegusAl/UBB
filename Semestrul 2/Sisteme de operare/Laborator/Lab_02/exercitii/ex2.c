#include <stdio.h>
#include <string.h>

void sortareCuvinte(int n, char cuvinte[][11]) {
		for(int i = 0; i < n-1; i++) {
			for(int j = i+1; j<n; j++) {
				if(strcmp(cuvinte[i], cuvinte[j]) > 0) {
					char tmp[11];
					strcpy(tmp, cuvinte[i]);
					strcpy(cuvinte[i], cuvinte[j]);
					strcpy(cuvinte[j], tmp);
				}
			}
		}
}

int main() {
	int n;
	printf("N = ");
	scanf("%d", &n);
	char cuvinte[n][11];
	printf("Dati cuvintele: \n");
	for(int i = 0; i<n; i++) {
		printf("cuvant[%d]: ", i+1);
		scanf("%s", cuvinte[i]);
	}
	
	sortareCuvinte(n, cuvinte);	

	printf("Cuvintele sortate alfabet: \n");
	for(int i = 0; i<n; i++) {
		printf("%s\n", cuvinte[i]);
	}

	return 0;
}
