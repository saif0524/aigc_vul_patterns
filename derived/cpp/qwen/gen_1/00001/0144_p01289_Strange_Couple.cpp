#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const double EPS = 1e-8;
int n, s, t;
int signs[N];
int adj[N][N];
double dp[N];
bool vis[N];

double dijkstra(int src, int dest) {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    for (int i = 1; i <= n; ++i) dp[i] = 1e18;
    dp[src] = 0.0;
    pq.push({0.0, src});
    
    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        
        for (int v = 1; v <= n; ++v) {
            if (adj[u][v] == 0) continue;
            double new_dist;
            if (signs[v]) {
                new_dist = dist + adj[u][v];
            } else {
                new_dist = dist + (1.0 / (double)count_if(adj[v] + 1, adj[v] + n + 1, [](int x) { return x > 0; })) * adj[u][v];
            }
            if (new_dist < dp[v]) {
                dp[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
    return dp[dest];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> s >> t) {
        if (n == 0 && s == 0 && t == 0) break;
        for (int i = 1; i <= n; ++i) {
            cin >> signs[i];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> adj[i][j];
            }
        }
        double result = dijkstra(s, t);
        if (result >= 1e18) cout << "impossible\n";
        else printf("%.8f\n", result);
    }
}