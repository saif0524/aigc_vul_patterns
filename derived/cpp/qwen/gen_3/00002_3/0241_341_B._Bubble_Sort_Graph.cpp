#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; ++i) {
        if (a[i] > a[i+1]) {
            adj[a[i]].push_back(a[i+1]);
            adj[a[i+1]].push_back(a[i]);
            swap(a[i], a[i+1]);
        }
    }
    vector<int> dp(n+1, 1);
    vector<bool> visited(n+1, false);
    function<int(int)> dfs = [&](int v) {
        if (visited[v]) return dp[v];
        visited[v] = true;
        for (int u : adj[v]) {
            dp[v] = max(dp[v], 1 + dfs(u));
        }
        return dp[v];
    };
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            result += dfs(i);
        }
    }
    cout << result;
}