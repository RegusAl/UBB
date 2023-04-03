#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

ifstream fin("graf.txt");

int n, inf = 100000000, sursa;
vector <int> G[100];

void BFS(int s) {
    cout<<"Ordinea descoperirii nodurilor: "<<s<<" ";
    vector <char> color;
    vector <int> distanta;
    for(int i = 0; i <=n; i++) {
        color.push_back('a');
        distanta.push_back(inf);
    }
    color[s] = 'g';
    distanta[s] = 0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int nodCurent = Q.front();
        Q.pop();
        for(auto x:G[nodCurent]) {
            if(color[x] == 'a') {
                color[x] = 'g';
                cout<<x<<" ";
                distanta[x] = distanta[nodCurent] + 1;
                Q.push(x);
            }
        }
        color[nodCurent] = 'n';
    }
    cout<<"Distantele fata de nodul sursa "<<s<<" sunt"<<endl;
    for(int i = 1; i<=n; i++) {
        cout<<i<<": ";
        if(distanta[i] == inf) {
            cout<<"-"<<endl;
        } else {
            cout<<distanta[i]<<endl;
        }
    }
}

int main() {
    fin>>n;
    int x, y;
    while(fin>>x>>y) {
        G[x].push_back(y);
    }
    cout<<"Sursa: ";
    cin>>sursa;
    BFS(sursa);
    return 0;
}