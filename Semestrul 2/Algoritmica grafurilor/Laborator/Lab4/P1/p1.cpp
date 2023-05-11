#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("/home/albert/Documents/UBB/Semestrul 2/Algoritmica grafurilor/Laborator/Lab4/P1/fisier.in");
int parinte[101], pruffer[101];

// gasim frunza de pe indexul cel mai mic
int frunzaMinima(int n) {
    int fm = 0, i = 0;
    while (i < n) {
        if (fm == parinte[i]) {
            fm++;
            i = -1;
        }
        i++;
    }
    return fm;
}

void codarePrufer(int n) {
    for(int i = 0; i<n-1; i++) {
        int fm = frunzaMinima(n);
        // adaug parintele frunzei
        pruffer[i] = parinte[fm];
        parinte[fm] = fm;
    }
}

int main() {
    int n;
    fin>>n;
    for(int i = 0; i<n; i++) {
        fin>>parinte[i];
    }
    codarePrufer(n);
    // afisare
    cout<<n-1<<endl;
    for(int i = 0; i<n-1; i++) {
        cout<<pruffer[i]<<" ";
    }

    return 0;
}
