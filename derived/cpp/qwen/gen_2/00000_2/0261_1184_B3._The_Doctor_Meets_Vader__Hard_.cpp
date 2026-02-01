#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int MAXS = 100010;
const int INF = 1e9 + 7;

int n, m, s, b, k;
vector<pair<int, int>> adj[MAXN];
vector<int> dist[MAXN];
int spaceship[MAXS][4];
int base[MAXS][3];
int dependency[MAXS][2];
int profit[MAXS];

void bfs(int src, int idx) {
    queue<int> q;
    q.push(src);
    dist[idx][src] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &e : adj[u]) {
            int v = e.first;
            if (dist[idx][v] == INF) {
                dist[idx][v] = dist[idx][u] + 1;
                q.push(v);
            }
        }
    }
}

int dp[1 << 20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, 1);
        adj[v].emplace_back(u, 1);
    }
    cin >> s >> b >> k;
    for(int i=1; i<=s; i++){
        cin >> spaceship[i][0] >> spaceship[i][1] >> spaceship[i][2] >> spaceship[i][3];
    }
    for(int i=1; i<=b; i++){
        cin >> base[i][0] >> base[i][1] >> base[i][2];
    }
    for(int i=0; i<k; i++){
        cin >> dependency[i][0] >> dependency[i][1];
    }
    for(int i=1; i<=s; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = INF;
        }
        bfs(spaceship[i][0], i);
    }
    for(int i=1; i<=s; i++){
        int max_profit = -INF;
        for(int j=1; j<=b; j++){
            if(spaceship[i][1] >= base[j][1] && spaceship[i][2] >= dist[i][base[j][0]]){
                max_profit = max(max_profit, base[j][2] - spaceship[i][3]);
            }
        }
        profit[i] = max_profit;
    }
    int mask_limit = 1 << s;
    for(int mask=0; mask<mask_limit; mask++){
        dp[mask] = -INF;
        for(int i=1; i<=s; i++){
            if(mask & (1 << (i-1))){
                bool can_use = true;
                for(int j=0; j<k; j++){
                    if(dependency[j][0] == i && !(mask & (1 << (dependency[j][1]-1)))){
                        can_use = false;
                    }
                }
                if(can_use){
                    dp[mask] = max(dp[mask], dp[mask ^ (1 << (i-1))] + profit[i]);
                }
            }
        }
    }
    cout << dp[mask_limit-1] << "\n";
}