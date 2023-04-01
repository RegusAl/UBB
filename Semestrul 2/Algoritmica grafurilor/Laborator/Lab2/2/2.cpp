#include <iostream>
#include <fstream>

#define matrix_size 10

using namespace std;

ifstream fin("fisier.in");

void afisare_matrice(int a[matrix_size][matrix_size], int n) {
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void matrice_inchidere_tranzitiva(int a[matrix_size][matrix_size], int n) {
    for(int k = 1; k<=n; k++) {
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) {
                if(a[i][j] == 0) {
                    a[i][j] = (a[i][k] && a[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, m, a[matrix_size][matrix_size] = {0};
    fin>>n>>m;
    int x, y;
    for(int i = 1; i<=m; i++) {
        fin>>x>>y;
        a[x][y] = 1;
    }
    cout<<"Matricea de adiacenta a grafului orientat:"<<endl;
    afisare_matrice(a, n);
    cout<<"Matricea inchiderii tranzitive: "<<endl;
    matrice_inchidere_tranzitiva(a, n);
    afisare_matrice(a, n);
    return 0;
}