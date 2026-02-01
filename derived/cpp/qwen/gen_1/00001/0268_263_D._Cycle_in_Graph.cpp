#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];
int visited[100001];
int parent[100001];
bool found_cycle = false;
vector<int> cycle;

void dfs(int u, int prev, int k) {
    if (found_cycle) return;
    visited[u] = true;
    parent[u] = prev;

    for (int v : adj[u]) {
        if (v == prev) continue;
        if (!visited[v]) {
            dfs(v, u, k);
        } else {
            found_cycle = true;
            int cur = u;
            cycle.push_back(cur);
            while (cur != v) {
                cur = parent[cur];
                cycle.push_back(cur);
            }
            cycle.push_back(u);
            break;
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, -1, k);
        }
        if (found_cycle) break;
    }

    reverse(cycle.begin(), cycle.end());
    int len = cycle.size();
    if (len < k + 1) {
        for (int i = 0; i < len; i++) {
            for (auto &nxt : adj[cycle[i]]) {
                if (find(cycle.begin(), cycle.end(), nxt) == cycle.end()) {
                    cycle.push_back(nxt);
                    break;
                }
            }
        }
    }

    cout << cycle.size() << "\n";
    for (int x : cycle) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}