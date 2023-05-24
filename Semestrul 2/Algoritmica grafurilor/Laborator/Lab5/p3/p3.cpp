#include <iostream>
#include <fstream>

using namespace std;

int n, m, x, y, a[101][101] = {0}, l[201] = {0}, p = 0;

void Euler(int k)
{
    for(int i=0;i<n;i++)
        if (a[k][i])
        {
            a[k][i] = a[i][k] = 0;
            Euler(i);
        }
    l[++p] = k;
}

int main() {
    ifstream fin("/home/albert/Documents/UBB/Semestrul 2/Algoritmica grafurilor/Laborator/Lab5/p3/fisier_in.txt");
    fin>>n>>m;
    for(int i = 0; i < m; i++) {
        fin>>x>>y;
        a[x][y] = a[y][x] = 1;
    }
    Euler(0);
    for(int i = 1; i<p; i++) {
        cout<<l[i]<<" ";
    }
    return 0;
}