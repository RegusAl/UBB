#include <iostream>
#include <fstream>
#define inf 10000000
using  namespace std;

ifstream fin("fisier.in");

int n, mat[10][10] = {0}, d[10][10] = {0};
int viz[100] = {0};

void lista_muchii() {
    int i, j;
    cout<<"Lista de muchii: "<<endl;
    cout<<n<<endl;
    while(fin>>i>>j) {
        cout << i << " " << j << endl;
        mat[i][j] = 1;
        mat[j][i] = 1;
    }
}

void matrice_adiacenta() {
    for(int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void noduri_izolate() {
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

}

int graf_regular() {
    int v[10] = {0};
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            if(mat[i][j]==1) {
                v[i]++;
            }
        }
    }
    for(int i = 1; i < n; i++) {
        if(v[i]!=v[i+1]) {
            return 0;
        }
    }
    return 1;
}

void matricea_distantelor() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j<=n; j++) {
            if(mat[i][j]==1)
                d[i][j] = 1;
            else
                d[i][j] = inf;
        }
    }
}

void roy_floyd() {
    for(int k = 1; k<=n; k++) {
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) {
                if(d[i][k]!=inf && d[k][j]!=inf) {
                    if(d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
    }
}

void afisare_matricea_distantelor() {
    for(int i = 1; i<=n; i++) {
        d[i][i] = 0;
        for(int j = 1; j<=n; j++) {
            if(d[i][j] == inf)
                cout<<"inf"<<" ";
            else
                cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}

void DFS(int x) {
    int i;
    viz[x] = 1;
    for(i = 1; i<=n; i++) {
        if(mat[x][i]==1 && viz[i]==0)
            DFS(i);
    }
}

int conex(int n) {
    DFS(1);
    for(int i = 1; i<=n; i++) {
        if(viz[i]==0)
            return 0;
    }
    return 1;
}

int main() {

    fin >> n;

    int i, j;
    lista_muchii();
    cout<<"----------"<<endl;

    cout<<"Matricea de adiacenta: "<<endl;
    matrice_adiacenta();
    cout<<"----------"<<endl;

    // noduri izolate
    noduri_izolate();
    cout<<"----------"<<endl;

    // determinare graf regular
    if(graf_regular()==0) {
        cout<<"Graful nu este regular!"<<endl;
    } else {
        cout<<"Graful este regular!"<<endl;
    }
    cout<<"----------"<<endl;

    // Matricea distantelor
    matricea_distantelor();

    // roy-floyd
    roy_floyd();

    // afisare matricea drumurilor
    afisare_matricea_distantelor();
    cout<<"----------"<<endl;

    if(conex(n)) {
        cout<<"Graful este conex."<<endl;
    } else {
        cout<<"Graful nu este conex."<<endl;
    }
    cout<<"----------"<<endl;

    fin.close();

    return 0;
}