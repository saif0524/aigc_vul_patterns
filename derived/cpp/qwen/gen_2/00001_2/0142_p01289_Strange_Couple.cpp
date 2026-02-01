#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const double EPS = 1e-9;
const double INF = 1e9;

int n, s, t;
int q[MAXN];
int a[MAXN][MAXN];
double dist[MAXN];
vector<pair<int, int>> adj[MAXN];
double dp[MAXN];
bool vis[MAXN];

void dijkstra(int src) {
    fill(dist, dist + n + 1, INF);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int u = pq.top().second;
        double d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

double dfs(int u) {
    if (vis[u]) return 0;
    vis[u] = true;
    if (u == t) return 0;
    double sum = 0, cnt = 0;
    for (auto [v, w] : adj[u]) {
        if (q[u] == 1 && dist[v] == dist[u] - w) continue; // Skip if there's a sign and not the shortest path
        sum += w + dfs(v);
        cnt++;
    }
    return cnt == 0 ? INF : sum / cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> s >> t){
        if(n == 0 && s == 0 && t == 0) break;
        for(int i = 1; i <= n; i++) cin >> q[i];
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
                if(a[i][j] > 0) adj[i].push_back({j, a[i][j]});
            }
        }
        dijkstra(t);
        fill(dp, dp + n + 1, -1);
        fill(vis, vis + n + 1, false);
        double result = dfs(s);
        if(result > INF - EPS) cout << "impossible\n";
        else cout << fixed << setprecision(8) << result << "\n";
    }
}