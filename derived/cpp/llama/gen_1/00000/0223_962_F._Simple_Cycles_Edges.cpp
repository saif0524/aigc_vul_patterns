#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100005;

vector<pair<int, int>> adj[MAX_N];
bool visited[MAX_N];
bool onCycle[MAX_N];
int parent[MAX_N];
int edgeId[MAX_N];
int discoveryTime[MAX_N];
int low[MAX_N];

int timer = 0;

void dfs(int u, int p) {
    visited[u] = true;
    discoveryTime[u] = timer;
    low[u] = timer;
    timer++;

    for (auto& e : adj[u]) {
        int v = e.first;
        int id = e.second;
        if (!visited[v]) {
            parent[v] = u;
            edgeId[v] = id;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == discoveryTime[v] && parent[u] != v) {
                onCycle[id] = true;
            }
        } else if (v != p) {
            low[u] = min(low[u], discoveryTime[v]);
            if (discoveryTime[v] < discoveryTime[u]) {
                onCycle[edgeId[u]] = true;
                onCycle[id] = true;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        edges.push_back(i);
    }
    dfs(0, -1);
    int count = 0;
    vector<int> result;
    for (int i = 0; i < m; i++) {
        if (onCycle[i]) {
            count++;
            result.push_back(i + 1);
        }
    }
    cout << count << "\n";
    sort(result.begin(), result.end());
    for (int x : result) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}