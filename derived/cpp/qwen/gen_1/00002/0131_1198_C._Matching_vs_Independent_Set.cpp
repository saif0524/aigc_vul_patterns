#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(3 * n);
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(i);
        adj[v].push_back(i);
        edges[i] = {u, v};
    }

    vector<int> matching(3 * n, -1);
    vector<int> visited(3 * n, 0);
    int timer = 0;

    function<bool(int)> dfs = [&](int u) -> bool {
        visited[u] = timer;
        for (int edge : adj[u]) {
            int v = (edges[edge].first == u ? edges[edge].second : edges[edge].first);
            if (matching[v] == -1) {
                matching[v] = edge;
                return true;
            }
            if (visited[matching[v]] != timer && dfs(matching[v])) {
                matching[v] = edge;
                return true;
            }
        }
        return false;
    };

    int cnt = 0;
    timer = 1;
    for (int i = 0; i < 3 * n; ++i) {
        if (dfs(i)) {
            ++cnt;
        }
        ++timer;
    }

    if (cnt == n) {
        cout << "Matching\n";
        for (int i = 0; i < 3 * n; ++i) {
            if (matching[i] != -1) {
                cout << matching[i] + 1 << ' ';
                --cnt;
                if (cnt == 0) break;
            }
        }
        cout << '\n';
        return;
    }

    vector<int> cmp(3 * n, -1);
    int component = 0;

    function<void(int, int)> paint = [&](int u, int c) {
        cmp[u] = c;
        for (int edge : adj[u]) {
            int v = (edges[edge].first == u ? edges[edge].second : edges[edge].first);
            if (cmp[v] == -1) {
                paint(v, c ^ 1);
            }
        }
    };

    for (int i = 0; i < 3 * n; ++i) {
        if (cmp[i] == -1) {
            paint(i, 0);
            ++component;
        }
    }

    vector<int>独立set;
    for (int i = 0; i < 3 * n; ++i) {
        if (cmp[i] == 0) {
           独立set.push_back(i + 1);
            if (独立set.size() == n) break;
        }
    }

    if (独立set.size() == n) {
        cout << "IndSet\n";
        for (int u : 独立set) {
            cout << u << ' ';
        }
        cout << '\n';
    } else {
        cout << "Impossible\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}