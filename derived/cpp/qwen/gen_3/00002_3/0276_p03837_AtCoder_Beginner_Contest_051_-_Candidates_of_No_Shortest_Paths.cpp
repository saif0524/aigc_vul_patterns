#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 1e9;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN][MAXN];

void floydWarshall(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) dist[i][j] = INF;
            else dist[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (auto edge : adj[i]) {
            int v = edge.first, w = edge.second;
            dist[i][v] = min(dist[i][v], w);
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    floydWarshall(n);
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(auto edge : adj[i]){
            int v = edge.first, c = edge.second;
            bool isShortestPath = false;
            for(int j=1; j<=n; j++){
                for(int k=1; k<=n; k++){
                    if(j != k && dist[j][k] == dist[j][i] + c + dist[v][k]){
                        isShortestPath = true;
                        break;
                    }
                }
                if(isShortestPath) break;
            }
            if(!isShortestPath) ans++;
        }
    }
    cout << ans/2;
    return 0;
}