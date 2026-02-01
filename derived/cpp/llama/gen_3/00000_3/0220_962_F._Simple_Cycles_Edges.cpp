#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<vector<pair<int, int>>> adj(MAXN);
vector<bool> vis(MAXN, false);
vector<bool> bridge(MAXN, false);
vector<int> low(MAXN), num(MAXN);
int counter = 0;

void dfs(int node, int prev, int pnum) {
    vis[node] = true;
    num[node] = low[node] = counter++;
    for (auto& edge : adj[node]) {
        int neighbor = edge.first;
        int edge_num = edge.second;
        if (!vis[neighbor]) {
            dfs(neighbor, node, edge_num);
            low[node] = min(low[node], low[neighbor]);
            if (low[neighbor] > num[node]) {
                bridge[edge_num] = true;
            }
        } else if (neighbor != prev) {
            low[node] = min(low[node], num[neighbor]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1, -1);
        }
    }
    vector<int> result;
    for (int i = 0; i < m; i++) {
        if (!bridge[i]) {
            result.push_back(i + 1);
        }
    }
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}