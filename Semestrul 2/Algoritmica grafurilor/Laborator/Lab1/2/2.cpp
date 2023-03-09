#include <iostream>
#include <fstream>

using  namespace std;

ifstream fin("/home/albert/Documents/UBB/Semestrul 2/Algoritmica grafurilor/Laborator/Lab1/1/fisier.in");

int main() {

    int n; // numarul de noduri
    fin >> n;
    int mat[10][10] = {0};
    int i, j;
    cout<<"Lista de muchii: "<<endl;
    cout<<n<<endl;
    while(fin>>i>>j) {
        cout << i << " " << j << endl;
        mat[i][j] = 1;
        mat[j][i] = 1;
    }

    cout<<"Matricea de adiacenta: "<<endl;
    for(int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }

    // noduri izolate
    int nr = 0;
    for(int i = 1; i<=n; i++) {
        int ok = 0;
        for (int j = 1; j<=n; j++) {
            if(mat[i][j] == 1) {
                ok = 1;
            }
        }
        if(ok==0) {
            cout << i << " este nod izolat." << endl;
            nr++;
        }
    }
    if(nr==0)
        cout<<"Nu exista noduri izolate!"<<endl;



    // determinare graf regular
    int v[10] = {0};
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            if(mat[i][j]==1) {
                v[i]++;
            }
        }
    }
    int ok = 1;
    for(i = 1; i < n; i++) {
        if(v[i]!=v[i+1]) {
            ok = 0;
        }
    }
    if(ok==0) {
        cout<<"Graful nu este regular!"<<endl;
    } else {
        cout<<"Graful este regular!"<<endl;
    }

//    int **drumuri = new int*[n];
//    for (int i = 1; i <= n; i++) {
//        drumuri[i] = new int[n];
//        for (int j = 1; j <= n; j++) {
//            if(mat[i][j] != 1) {
//                drumuri[i][j] = -1;
//            } else {
//                drumuri[i][j] = mat[i][j];
//            }
//
//        }
//    }
//
//    for (int k = 1; k <= n; k++) {
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                if (drumuri[i][k]==-1 && drumuri[k][j]==-1) {
//                    if(drumuri[i][j] > drumuri[i][k] + drumuri[k][j])
//                        drumuri[i][j] += drumuri[i][k] + drumuri[k][j];
//                }
//            }
//        }
//    }
//
//    cout << "Matricea drumurilor este: " << endl;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cout << drumuri[i][j] << " ";
//        }
//        cout << endl;
//    }

    fin.close();

    return 0;
}