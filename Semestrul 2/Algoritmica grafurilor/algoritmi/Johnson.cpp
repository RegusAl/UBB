#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1<<30;
const int NMAX = 1005;

int n, m;
vector<vector<pair<int, int>>> G(NMAX), newG(NMAX);

vector<int> BellmanFord(int source) {
    vector<int> dist(n+1);

    for(int i = 0; i <= n; ++i) {
        dist[i] = INF;
    }
    dist[source] = 0;

    for(int i = 0; i <= n; ++i) {
        for(auto p : G[i]) {
            int u = i;
            int v = p.first;
            int w = p.second;

            if(dist[u] != NMAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int i = 0; i <= n; ++i) {
        for(auto p : G[i]) {
            int u = i;
            int v = p.first;
            int w = p.second;

            if(dist[u] != NMAX && dist[u] + w < dist[v]) {
                vector<int> negSol;
                return negSol;
            }
        }
    }

    return dist;
}

vector<int> Dijkstra(int source) {
    queue<int> q;
    vector<int> dist(n+1);
    q.push(source);

    for(int i = 1; i <= n; ++i) {
        if(i != source) {
            dist[i] = INF;
        }
        else {
            dist[i] = 0;
        }
    }

    while(!q.empty()) {
        int val = q.front();
        q.pop();
        for(auto p : G[val]) {
            if(dist[val] + p.second < dist[p.first]) {
                q.push(p.first);
                dist[p.first] = dist[val] + p.second;
            }
        }
    }

    return dist;
}

void Johnson() {

    //Adaugam un nou nod
    for(int i = 1; i <= n; ++i) {
        pair<int, int> p = make_pair(i, 0);
        G[0].push_back(p);
    }

    //Facem BellmanFord
    vector<int> dist = BellmanFord(0);
    if(dist.empty()) {
        cout << -1;
        return;
    }

    //Reponderam
    for(int i = 1; i <= n; ++i) {
        for(auto p : G[i]) {
            pair<int,int> newP;
            newP = p;
            newP.second += (dist[i] - dist[newP.first]);
            newG[i].push_back(newP);
        }
    }

    //Afisam graful reponderat
    for(int i = 1; i <= n; ++i) {
        for(auto p : newG[i]) {
            cout<< i-1 << " " << p.first-1 << " " << p.second << '\n';
        }
    }

    //Facem Dijkstra pt toate nodurile
    for(int i = 1; i <= n; ++i) {
        dist = Dijkstra(i);
        for(int i = 1; i <= n; ++i) {
            if(dist[i] == INF) {
                cout << "INF";
            }
            else {
                cout << dist[i];
            }
            cout << " ";
        }
        cout << '\n';
    }
}

int main() {
    ifstream f("/home/albert/Documents/UBB/Semestrul 2/Algoritmica grafurilor/algoritmi/fisier.in");

    f >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int x, y, w;
        f >> x >> y >> w;
        x++, y++;
        pair<int, int> p = make_pair(y, w);
        G[x].push_back(p);
    }

    Johnson();

    f.close();
    return 0;
}