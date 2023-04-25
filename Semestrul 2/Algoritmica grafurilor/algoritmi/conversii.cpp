#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("fisier.in");

int n, matAdiacenta[101][101], matIncidenta[101][101], listaVecini[101][101], matIncidenta2[101][101];

int main() {
    int x, y;
    int k = 1;
    fin>>n;

    // din 'Lista vecinilor in Matricea de Adiacenta si de Incidenta'
    while(fin>>x>>y) {
        matAdiacenta[x][y]=matAdiacenta[y][x]=1;
        matIncidenta[k][x]=matIncidenta[k][y]=1;
        k++;
    }

    cout<<"Matricea de adiacenta"<<endl;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<matAdiacenta[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Matricea de incidenta"<<endl;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<matIncidenta[i][j]<<" ";
        }
        cout<<endl;
    }

    // din 'Matricea de adiacenta' in 'Matricea de incidenta'
    k = 0;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            if(matAdiacenta[i][j]==1) {
                k++;
                matAdiacenta[i][j]=matAdiacenta[j][i]=0;
                matIncidenta2[k][j]=matIncidenta2[k][i]=1;
            }
        }
    }

    cout<<"------"<<endl;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<matIncidenta2[i][j]<<" ";
        }
        cout<<endl;
    }

    // din 'Matricea de incidenta in matrice de adiacenta'

    x = 0, y = 0;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            if(matIncidenta[i][j]==1) {
                y = x;
                x = j;
            }
        }
        matAdiacenta[x][y]=matAdiacenta[y][x]=1;
    }

    cout<<"Matricea de adiacenta"<<endl;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<matAdiacenta[i][j]<<" ";
        }
        cout<<endl;
    }

    // lista vecinilor din matricea de adiacenta

    for(int i = 1; i<=n; i++) {
        cout<<i<<": ";
        for(int j = 1; j<=n; j++) {
            if(matAdiacenta[i][j]==1)
                cout<<j<<" ";
        }
        cout<<endl;
    }

}