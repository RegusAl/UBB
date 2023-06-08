#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

#define dim 100

using namespace std;

ifstream fin("/home/albert/Documents/UBB/Semestrul 2/Algoritmica grafurilor/algoritmi/fisier.in");

int n, m, g[dim][dim];

bool BFS(int s, int d, int parent[]){
    queue <int> Q;
    bool visited[dim];
    memset(visited, 0, sizeof(visited));

    visited[s] = true;
    parent[s] = -1;

    Q.push(s);
    while(!Q.empty()){
        int nod = Q.front();
        Q.pop();
        for(int i = 0; i < n; i++){
            if(visited[i] == false && g[nod][i] > 0){
                if(i == d){
                    parent[i] = nod;
                    return true;
                }
                Q.push(i);
                parent[i] = nod;
                visited[i] = true;

            }
        }
    }

    // nu am gasit drum de la s la t
    return false;
}

void Ford_Fulkerson(int s, int d){

    int parent[dim];
    int max_flow = 0;

    while(BFS(s, d, parent)){
        int path_flow = INT_MAX;
        for(int i = d; i != s; i = parent[i]){
            int u = parent[i];
            path_flow = min(path_flow, g[u][i]);
        }

        for(int i = d; i != s; i = parent[i]){
            int u = parent[i];
            g[u][i] -= path_flow;
            g[i][u] += path_flow;
        }

        max_flow += path_flow;
    }

    cout<< "Fluxul maxim este: " << max_flow;

}

int main(){
    int x, y, capacitate;

    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x;
        fin >> y;
        fin >> capacitate;
        g[x][y] = capacitate;
    }

    Ford_Fulkerson(0, n - 1);
}