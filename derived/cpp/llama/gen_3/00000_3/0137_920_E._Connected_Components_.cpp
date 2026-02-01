#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int N = 200005;

int n, m;
vector<int> edges[N];
bool vis[N];
set<pair<int, int>> non_edges;

void dfs(int u, vector<int>& component) {
    vis[u] = true;
    component.push_back(u);
    for (int v = 1; v <= n; v++) {
        if (!vis[v] && non_edges.find({u, v}) == non_edges.end() && non_edges.find({v, u}) == non_edges.end()) {
            dfs(v, component);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        non_edges.insert({min(u, v), max(u, v)});
    }

    vector<vector<int>> components;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> component;
            dfs(i, component);
            components.push_back(component);
        }
    }

    cout << components.size() << '\n';
    vector<int> sizes;
    for (auto& comp : components) {
        sizes.push_back(comp.size());
    }
    sort(sizes.begin(), sizes.end());
    for (int size : sizes) {
        cout << size << ' ';
    }
    cout << '\n';

    return 0;
}