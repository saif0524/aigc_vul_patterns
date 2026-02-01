#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct Edge {
    int to, weight;
};

vector<Edge> adj[MAXN];
int parent[MAXN], rank[MAXN], dist[MAXN];
bool visited[MAXN];

int find(int x) {
    if (parent[x] != x) {
        int origin = parent[x];
        parent[x] = find(parent[x]);
        dist[x] += dist[origin];
    }
    return parent[x];
}

bool unionSets(int x, int y, int w) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            dist[rootY] = dist[x] - dist[y] + w;
        } else {
            parent[rootX] = rootY;
            dist[rootX] = dist[y] - dist[x] - w;
            if (rank[rootX] == rank[rootY]) {
                rank[rootY]++;
            }
        }
        return true;
    } else {
        return dist[x] - dist[y] == w;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        parent[i] = i;
        rank[i] = 0;
        dist[i] = 0;
        visited[i] = false;
    }
    for(int i=0; i<M; i++){
        int L, R, D;
        cin >> L >> R >> D;
        if(!unionSets(L, R, D)){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}