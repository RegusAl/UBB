#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

ifstream fin("graf.txt");

int n, inf = 100000000, sursa;
vector <int> G[100];

void DFS_VISIT(vector <pair <int, char> >& Attr, vector <pair <int, int>>&Time, int s, int& time) {
    cout<<s<<" ";
    time++;
    Time[s].first = time;
    Attr[s].second = 'g';
    for(auto x:G[s]) {
        if(Attr[x].second == 'a') {
            Attr[x].first = s;
            DFS_VISIT(Attr, Time, x, time);
        }
    }
    Attr[s].second = 'n';
    time++;
    Time[s].second = time;
}

void DFS(int s, vector <pair <int, char>>&Attr, vector <pair <int, int>>&Time) {
    cout<<"Ordinea descoperirii nodurilor: "<<s<<" ";
    for(int i = 0; i<=n; i++) {
        Attr.push_back(make_pair(-1, 'a'));
        Time.push_back(make_pair(0, 0));
    }
    int time = 0;
    for(int i = 1; i <= n; i++) {
        if(Attr[i].second == 'a') {
            DFS_VISIT(Attr, Time, i, time);
        }
    }
}

int main() {
    fin>>n;
    int x, y;
    vector <pair <int, char>> Attr;
    vector <pair <int, int>> Time;
    while(fin>>x>>y) {
        G[x].push_back(y);
    }
    cout<<"Sursa: ";
    cin>>sursa;
    DFS(sursa, Attr, Time);
    return 0;
}