#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
ifstream fin("/home/albert/Documents/UBB/Semestrul 2/Algoritmica grafurilor/algoritmi/fisier.in");
int n,x,nrAparitii[100000],y,parent[100000];
queue<int> q;
void decodarePrufer()
{

    fin>>n;
    //initializare
    for(int i=0;i<n;i++)
    {
        //citim elementele din codul prufer
        fin>>x;
        q.push(x);
        //nrAparitii[x] reprezinta numarul de aparitii ale nodului x in codul prufer
        nrAparitii[x]++;
        parent[i]=-1;
    }
    parent[n]=-1;

    for(int i=1;i<=n;i++)
    {
        //cautam nodul cu gradul minim
        x=q.front();
        //cautam primul nod care nu apare in codul prufer
        y=0;
        while(nrAparitii[y]!=0)
            y++;
        parent[y]=x;
        q.pop();
        q.push(y);
        nrAparitii[y]++;
        nrAparitii[x]--;
    }
    //afisam parintii
    cout<<n+1<<'\n';
    for(int i=0;i<=n;i++)
    {
        cout<<parent[i]<<" ";
    }
}

int main() {
    decodarePrufer();
    return 0;
}