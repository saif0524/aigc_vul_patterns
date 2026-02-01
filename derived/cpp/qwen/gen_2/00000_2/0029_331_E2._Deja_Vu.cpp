#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 55;
const int MOD = 1000000007;

vector<pair<int, vector<int>>> adj[N];
int dp[N][N * N];
bool visited[N];
int path[N];
int path_len;

bool dfs(int node, int len, int target_len, int parent) {
    if (len == target_len) {
        if (node == parent) {
            path_len = len;
            return true;
        }
        return false;
    }
    visited[node] = true;
    path[len] = node;
    for (auto [nex, vis] : adj[node]) {
        bool match = true;
        if (vis.size() + len > target_len) continue;
        for (int i = 0; i < vis.size(); i++) {
            if (path[len + i] != vis[i]) {
                match = false;
                break;
            }
        }
        if (match && dfs(nex, len + vis.size(), target_len, parent)) {
            visited[node] = false;
            return true;
        }
    }
    visited[node] = false;
    return false;
}

void find_path(int n) {
    for (int len = 1; len <= 2 * n; ++len) {
        for (int i = 1; i <= n; ++i) {
            fill(path, path + N, 0);
            fill(visited, visited + N, false);
            if (dfs(i, 0, len, i)) {
                cout << len << "\n";
                for (int j = 0; j < len; ++j) {
                    cout << path[j] << (j < len - 1 ? " " : "\n");
                }
                return;
            }
        }
    }
    cout << "0\n";
}

void count_paths(int n) {
    for (int len = 1; len <= 2 * n; ++len) {
        ll count = 0;
        for (int i = 1; i <= n; ++i) {
            fill(dp[0], dp[0] + N * N, 0);
            dp[i][0] = 1;
            for (int l = 1; l < len; ++l) {
                fill(dp[l], dp[l] + N * N, 0);
                for (int j = 1; j <= n; ++j) {
                    for (auto [nex, vis] : adj[j]) {
                        if (l + vis.size() <= len) {
                            bool match = true;
                            for (int k = 0; k < vis.size(); k++) {
                                if (vis[k] != path[l + k]) {
                                    match = false;
                                    break;
                                }
                            }
                            if (match) {
                                dp[nex][l + vis.size()] = (dp[nex][l + vis.size()] + dp[j][l]) % MOD;
                            }
                        }
                    }
                }
            }
            count = (count + dp[i][len]) % MOD;
        }
        cout << count << "\n";
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y, k;
        cin >> x >> y >> k;
        vector<int> vis(k);
        for(int j=0; j<k; j++){
            cin >> vis[j];
        }
        adj[x].push_back({y, vis});
    }
    //find_path(n);
    count_paths(n);
}