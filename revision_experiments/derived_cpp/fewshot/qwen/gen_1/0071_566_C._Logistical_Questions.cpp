#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<pair<int, int>> adj[N];
int n;
long long w[N];
double best_cost = 1e18;
int best_city = -1;
long long total_weight = 0;

void dfs(int u, int p, long long sum, long long weight) {
    sum += weight;
    total_weight += w[u];
    double cost = sum + (total_weight - w[u]) *2.0;
    if (cost < best_cost) {
        best_cost = cost;
        best_city = u;
    }
    for (auto& [v, l] : adj[u]) {
        if (v == p) continue;
        dfs(v, u, sum + (w[u] *2LL * l), l * w[u]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> w[i];
    for(int i=1;i<n;i++){
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].emplace_back(v, l);
        adj[v].emplace_back(u, l);
    }
    dfs(1, 0, 0, 0);
    cout << best_city <<   << fixed << setprecision(15) << best_cost << "\n";
    return 0;
}