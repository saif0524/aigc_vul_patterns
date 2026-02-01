#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50;
const int MAXM = 100005;
const int MOD = 1000000007;

vector<pair<int, vector<int>>> graph[MAXN];
int dp[MAXN][105][105];
int path[105];
int path_len = 0;

void solve_e1() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        --u, --v;
        vector<int> visions(k);
        for (int j = 0; j < k; ++j) {
            cin >> visions[j];
            --visions[j];
        }
        graph[u].emplace_back(v, visions);
    }

    dp[0][0][0] = 1;
    int max_len = 0;

    for (int len = 0; len < 2 * n; ++len) {
        for (int node = 0; node < n; ++node) {
            for (int pos = 0; pos <= len; ++pos) {
                if (dp[node][len][pos] == 0) continue;
                for (auto& [next_node, visions] : graph[node]) {
                    int new_pos = pos;
                    int next_len = len + 1;
                    bool valid = true;
                    for (int i = 0; i <visions.size(); ++i) {
                        if (new_pos + i + 1 > next_len) {
                            valid = false;
                            break;
                        }
                        if (visions[i] != path[new_pos + i]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        dp[next_node][next_len][new_pos + visions.size()] = (dp[next_node][next_len][new_pos + visions.size()] + dp[node][len][pos]) % MOD;
                        max_len = max(max_len, next_len);
                    }
                }
                path[len + 1] = node;
            }
        }
    }

    for (int len = 1; len <= max_len; ++len) {
        for (int node = 0; node < n; ++node) {
            if (dp[node][len][len] > 0) {
                path_len = len;
                for (int i = len; i > 0; --i) path[i] = path[i - 1];
                path[0] = node;
                cout << path_len << "\n";
                for (int i = 0; i < path_len; ++i) {
                    cout << path[i] + 1;
                    if (i != path_len - 1) cout << " ";
                }
                cout << "\n";
                return;
            }
        }
    }

    cout << "0\n";
}

void solve_e2() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        --u, --v;
        vector<int> visions(k);
        for (int j = 0; j < k; ++j) {
            cin >> visions[j];
            --visions[j];
        }
        graph[u].emplace_back(v, visions);
    }

    vector<int> ans(2 * n + 1, 0);

    for (int node = 0; node < n; ++node) {
        dp[node][0][0] = 1;
    }

    for (int len = 0; len < 2 * n; ++len) {
        for (int node = 0; node < n; ++node) {
            for (int pos = 0; pos <= len; ++pos) {
                if (dp[node][len][pos] == 0) continue;
                for (auto& [next_node, visions] : graph[node]) {
                    int new_pos = pos;
                    int next_len = len + 1;
                    bool valid = true;
                    for (int i = 0; i <visions.size(); ++i) {
                        if (new_pos + i + 1 > next_len) {
                            valid = false;
                            break;
                        }
                        if (visions[i] != path[new_pos + i]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        dp[next_node][next_len][new_pos + visions.size()] = (dp[next_node][next_len][new_pos + visions.size()] + dp[node][len][pos]) % MOD;
                        path[next_len] = next_node;
                        if (next_node == node) {
                            ans[next_len] = (ans[next_len] + dp[node][len][pos]) % MOD;
                        }
                    }
                }
                path[len + 1] = node;
            }
        }
    }

    for (int len = 1; len <= 2 * n; ++len) {
        cout << ans[len] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve_e2();
    return 0;
}