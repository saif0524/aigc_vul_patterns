#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

const int maxn = 2e5 + 5;

int n, q;
int a[maxn];
int in_degree[maxn];
vector<int> g[maxn];
unordered_map<int, int> cycles;
unordered_map<int, vector<pair<int, int>>> graph;

void dfs(int u, vector<int> &path) {
    if (cycles.find(u) != cycles.end()) {
        int idx = cycles[u];
        int len = path.size() - idx;
        for (int i = idx; i < path.size(); ++i) {
            graph[path[idx]].emplace_back(path[i], len);
        }
    }
    else {
        cycles[u] = path.size();
        path.push_back(u);
        dfs(a[u], path);
        path.pop_back();
    }
}

int count(int m, int y) {
    int ans = 0;
    if (graph.find(y) == graph.end()) return 0;
    for (const auto &p : graph[y]) {
        int u = p.first, len = p.second;
        if ((m - 1) % len == 0) ++ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (cycles.find(i) == cycles.end()) {
            vector<int> path;
            dfs(i, path);
        }
    }
    cin >> q;
    while (q--) {
        long long m;
        int y;
        cin >> m >> y;
        int ans = count(m, y);
        for (int i = 1; i <= n; ++i) {
            if (cycles.find(i) == cycles.end()) continue;
            vector<int> &path = graph[i];
            if (m >= path.size()) {
                int len = path.size();
                int idx = (m - 1) % len;
                int start = path[idx];
                if (start == y) ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}