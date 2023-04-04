#include <iostream>
#include <fstream>
#include <queue>

#define inf 10000000

using namespace std;

ifstream fin("1.txt");

void Dijkastra_queue(int matrix[10][10], int cost[10][10], int cost_din_sursa[10], int size) {
    int start = 0;
    priority_queue<int,vector<int>, greater<int>> queue;
    for(int i = 0; i<size; i++) {
        queue.push(i);
    }
    cost_din_sursa[start] = 0;
    while(!queue.empty()) {
        int u = queue.top();
        queue.pop();
        for(int i = 0; i<size; i++) {
            if(matrix[u][i] == 1) {
                if(cost_din_sursa[u] != inf && cost_din_sursa[i] > cost_din_sursa[u] + cost[u][i]) {
                    cost_din_sursa[i] = cost_din_sursa[u] + cost[u][i];
                }
            }
        }
    }
    for(int i = 0; i<size; i++) {
        cout<<"Costul de la "<<start<<" la nodul "<<i<<" este "<<cost_din_sursa[i]<<endl;
    }
}

int main() {
    int n, m, nod_start, matrix[10][10], cost[10][10];
    fin>>n>>m>>nod_start;
    int x, y, cost_drum;
    while(fin>>x>>y>>cost_drum) {
        matrix[x][y] = 1;
        cost[x][y] = cost_drum;
    }
    int cost_din_sursa[10];
    for(int k = 0; k<n; k++) {
        cost_din_sursa[k] = inf;
    }
    Dijkastra_queue(matrix, cost, cost_din_sursa, n);
    return 0;
}