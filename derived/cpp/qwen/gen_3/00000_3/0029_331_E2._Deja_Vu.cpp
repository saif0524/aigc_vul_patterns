#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 55;
const int MAXM = 5e4 + 5;
const int MAXL = 105;

int n, m;
vector<pair<int, vector<int>>> adj[MAXN];
vector<int> path;
int dp[MAXN][2 * MAXN][MAXM];
bool found;

void find_path(int u, int len, int street_id) {
    if (len > 2 * n || found) return;
    if (len > 0 && path.back() == path[0]) {
        found = true;
        return;
    }
    for (auto &[v, visions] : adj[u]) {
        if (found) return;
        int next_street_id = (street_id + 1) % m;
        if (visions == dp[v][len + 1][next_street_id]) {
            path.push_back(v);
            find_path(v, len + 1, next_street_id);
            if (found) return;
            path.pop_back();
        }
    }
}

void solve_subproblem_e1() {
    for (int u = 1; u <= n; ++u) {
        path = {u};
        find_path(u, 0, -1);
        if (found) {
            cout << path.size() << "\n";
            for (int shop : path) {
                cout << shop << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << 0 << "\n";
}

void solve_subproblem_e2() {
    vector<int> result(2 * n + 1, 0);
    for (int u = 1; u <= n; ++u) {
        for (int len = 1; len <= 2 * n; ++len) {
            for (int street_id = 0; street_id < m; ++street_id) {
                dp[u][len][street_id] = -1;
            }
        }
    }
    for (int len = 1; len <= 2 * n; ++len) {
        for (int street_id = 0; street_id < m; ++street_id) {
            for (int u = 1; u <= n; ++u) {
                if (dp[u][len][street_id] != -1) {
                    for (auto &[v, visions] : adj[u]) {
                        int next_street_id = (street_id + 1) % m;
                        if (visions == dp[v][len + 1][next_street_id]) {
                            dp[v][len + 1][next_street_id] = u;
                        }
                    }
                }
            }
        }
    }
    for (int u = 1; u <= n; ++u) {
        for (int len = 1; len <= 2 * n; ++len) {
            for (int street_id = 0; street_id < m; ++street_id) {
                if (dp[u][len][street_id] == u) {
                    result[len]++;
                    result[len] %= MOD;
                }
            }
        }
    }
    for (int len = 1; len <= 2 * n; ++len) {
        cout << result[len] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, k;
        cin >> u >> v >> k;
        vector<int> visions(k);
        for(int j = 0; j < k; j++){
            cin >> visions[j];
        }
        adj[u].emplace_back(v, visions);
    }
    solve_subproblem_e2();
    return 0;
}