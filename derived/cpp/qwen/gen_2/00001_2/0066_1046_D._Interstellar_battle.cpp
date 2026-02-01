#include <bits/stdc++.h>
using namespace std;

typedef double db;
const int MAXN = 100005;

int n, q;
db p[MAXN];
vector<int> adj[MAXN];
db exp_kingdoms[MAXN];

db dfs(int u, int par) {
    db sum = p[u];
    for (int v : adj[u]) {
        if (v == par) continue;
        sum += dfs(v, u);
    }
    exp_kingdoms[u] = sum;
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i =0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    db total_exp = 0.0;
    for(int i =0; i < n; i++) total_exp += exp_kingdoms[i] * (1.0 - p[i]);
    cin >> q;
    while(q--){
        int u;
        db np;
        cin >> u >> np;
        total_exp -= exp_kingdoms[u] * (1.0 - p[u]);
        p[u] = np;
        db new_sum = p[u];
        for(int v : adj[u]){
            new_sum += exp_kingdoms[v];
        }
        total_exp += new_sum * (1.0 - p[u]);
        exp_kingdoms[u] = new_sum;
        cout << fixed << setprecision(5) << total_exp << "\n";
    }
    return 0;
}