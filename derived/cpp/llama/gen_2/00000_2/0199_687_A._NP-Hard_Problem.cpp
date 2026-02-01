#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int maxn = 100005;

vector<int> g[maxn];
bool color[maxn];
bool used[maxn];
int t;

tuple<bool, int, int> dfs(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u]) {
            color[u] = !color[v];
            auto tmp = dfs(u);
            if (!get<0>(tmp)) return {false, 0, 0};
            if (get<1>(tmp) && !get<2>(tmp)) return {true, u, 0};
            if (!get<1>(tmp) && get<2>(tmp)) return {true, 0, u};
        } else if (color[u] == color[v]) return {false, 0, 0};
    }
    return {true, 0, 0};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            color[i] = true;
            auto tmp = dfs(i);
            if (!get<0>(tmp)) {
                cout << "-1\n";
                return 0;
            }
            if (get<1>(tmp) && !get<2>(tmp)) {
                t = get<1>(tmp);
            }
            if (!get<1>(tmp) && get<2>(tmp)) {
                t = get<2>(tmp);
            }
        }
    }

    vector<int> first, second;
    for (int i = 0; i < n; i++) {
        if (i != t) {
            if (color[i]) first.push_back(i + 1);
            else second.push_back(i + 1);
        }
    }

    if (first.empty() || second.empty()) {
        cout << "-1\n";
        return 0;
    }

    cout << first.size() << '\n';
    for (int x : first) cout << x << ' ';
    cout << '\n';
    cout << second.size() << '\n';
    for (int x : second) cout << x << ' ';
    cout << '\n';
}