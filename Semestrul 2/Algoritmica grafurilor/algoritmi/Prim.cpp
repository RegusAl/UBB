#include <iostream>
#include <fstream>

using namespace std;

fstream fin("/home/albert/Documents/UBB/Semestrul 2/Algoritmica grafurilor/algoritmi/fisier.in");

const int inf = 1000000000;
int a[101][101], viz[101], c[101], t[101];

void Prim()
{
    int n, m;
    fin >> n >>m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                a[i][j] = inf;
    for(int p,q,cost,i=1;i<=m;i++)
    {   fin>>p>>q>>cost;
        a[p][q]=cost;
        a[q][p]=cost;
    }
    for (int j = 1; j <= n; j++)
    {
        c[j] = a[1][j];
        if (j != 1) t[j] = 1;
    }

    viz[1] = 1; c[0] = inf;
    int cost=0;
    for (int k = 2; k <= n; k++)
    {
        int min_c = 0;
        for (int i = 1; i <= n; i++)
            if (!viz[i] and c[i] < c[min_c])
                min_c = i;
        viz[min_c] = 1;
        for (int i = 1; i <= n; i++)
            if (!viz[i] and c[i] >a[min_c][i])
            {
                c[i] = a[min_c][i];
                t[i] = min_c;
            }
    }
    for(int i=1;i<=n;i++)
        cost+=c[i];
    cout<<cost<<'\n';
    for(int i=1;i<=n;i++)
        cout<<t[i]<<' ';
}

int main() {
    Prim();
    return 0;
}