#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define inf 10000000

using namespace std;

ifstream fin("graf.txt");

vector <int> Graf[100];
queue <int> Queue;

int Parinte[100], Distanta[100], n, sursa, destinatie;

void citire() {
    cout<<"Nodul sursa: ";
    cin>>sursa;
    cout<<"Nodul destinatie: ";
    cin>>destinatie;
    fin>>n;
    int x, y;
    while(fin>>x>>y) {
        Graf[x].push_back(y);
    }
}

void Moore(int sursa) {
    for(int i = 1; i<=n; i++) {
        Parinte[i] = -1;
        Distanta[i] = inf;
    }
    Distanta[sursa] = 0;
    Parinte[sursa] = 0;
    Queue.push(sursa);
    while (!Queue.empty()) {
        int nodCurent = Queue.front();
        Queue.pop();
        for(auto x : Graf[nodCurent]) {
            if(Distanta[x] == inf) {
                Distanta[x] = Distanta[nodCurent] + 1;
                Parinte[x] = nodCurent;
                Queue.push(x);
            }
        }
    }
}

void getParinte(int nod) {
    if(Parinte[nod] == 0) {
        cout<<nod<<" ";
        return;
    }
    getParinte(Parinte[nod]);
    cout<<nod<<" ";
}

void drum(int sursa, int destinatie) {
    int nod = destinatie;
    if(Distanta[nod] == inf) {
        cout<<"Nu se poate ajunge la nodul "<<destinatie<<" din nodul "<<sursa<<endl;
        return;
    }
    getParinte(destinatie);
}

int main() {
    citire();
    Moore(sursa);
    drum(sursa, destinatie);
    return 0;
}