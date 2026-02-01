#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1;

int n;
long long w[MAXN];
vector<pair<int, int>> adj[MAXN];
long long total_weight;
long double best_cost;
int best_city;

void dfs(int u, int p, long long dist, long long path_weight, long long path_sum) {
    total_weight += w[u] * dist;
    path_weight += w[u];
    path_sum += w[u] * dist;
    for (auto [v, wv] : adj[u]) {
        if (v != p) {
            dfs(v, u, dist + wv, path_weight, path_sum + path_weight * wv);
        }
    }
    if (u != 1) {
        long double cost = total_weight - 2 * path_sum + path_weight * dist;
        if (cost < best_cost) {
            best_cost = cost;
            best_city = u;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i < n; i++){
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].emplace_back(v, l);
        adj[v].emplace_back(u, l);
    }
    best_cost = 1e18;
    dfs(1, 0, 0, 0, 0);
    cout << best_city << " " << sqrt(best_cost) << "\n";
}