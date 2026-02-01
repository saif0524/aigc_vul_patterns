#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int MAX_N = 3e5 + 10;

vector<int> g[MAX_N];
vector<int> d(MAX_N);
vector<pair<int, int>> edges;

void dfs(int u, int p, vector<int>& used) {
    used[u] = 1;
    for (int v : g[u]) {
        if (v == p || used[v]) continue;
        dfs(v, u, used);
    }
}

vector<int> bfs(int start, vector<int>& used) {
    queue<int> q;
    q.push(start);
    used[start] = 1;
    vector<int> res;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int v : g[u]) {
            if (!used[v]) {
                q.push(v);
                used[v] = 1;
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int cnt1 = 0, cnt_minus1 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        if (d[i] == 1) cnt1++;
        if (d[i] == -1) cnt_minus1++;
    }

    if (cnt1 % 2 == 1 && cnt_minus1 == 0) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.emplace_back(u, v);
    }

    vector<int> used(n + 1);
    dfs(1, -1, used);

    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1 && used[i]) {
            for (int v : g[i]) {
                if (used[v]) {
                    for (const auto& edge : edges) {
                        if ((edge.first == i && edge.second == v) || (edge.first == v && edge.second == i)) {
                            res.push_back(edge);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }

    if (cnt1 % 2 == 1) {
        for (int i = 1; i <= n; i++) {
            if (d[i] == -1 && used[i]) {
                for (int v : g[i]) {
                    if (used[v]) {
                        for (const auto& edge : edges) {
                            if ((edge.first == i && edge.second == v) || (edge.first == v && edge.second == i)) {
                                res.push_back(edge);
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }

    cout << res.size() << '\n';
    int cnt = 1;
    for (const auto& edge : edges) {
        bool flag = false;
        for (const auto& e : res) {
            if ((e.first == edge.first && e.second == edge.second) || (e.first == edge.second && e.second == edge.first)) {
                flag = true;
                break;
            }
        }
        if (flag) cout << cnt << '\n';
        cnt++;
    }

    return 0;
}