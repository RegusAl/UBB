#include <iostream>
#include <fstream>

#define inf 1000000

using namespace std;

ifstream fin("/home/albert/Documents/UBB/Semestrul 2/Algoritmica grafurilor/algoritmi/fisier.in");
int n, m, s, a[100][100] = {0}, d[101], p[101];

void Bellman_Ford(int sursa) {
    for(int i = 0; i<n; i++) {
        d[i] = inf;
        p[i] = sursa;
    }
    d[sursa] = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(a[i][j]) {
                if(d[j] > d[i]+a[i][j]) {
                    d[j] = d[i] + a[i][j];
                    p[j] = i;
                }
            }
        }
    }
    //drumul
    for(int i = 0; i<n; i++) {
        cout<<d[i]<<" ";
    }
}

int main() {
    fin>>n>>m>>s;
    for(int j = 0; j<m; j++) {
        int x, y, c;
        fin>>x>>y>>c;
        a[x][y] = c;
    }
    Bellman_Ford(s);
    return 0;
}