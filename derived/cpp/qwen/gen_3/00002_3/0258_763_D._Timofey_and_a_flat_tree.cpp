#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<unordered_map<string, int>> cnt;
vector<int> ans;
string dfs(int u, int p) {
    string s = "(";
    for (auto &v : adj[u]) {
        if (v == p) continue;
        s += dfs(v, u);
    }
    s += ")";
    if (cnt[u].count(s) == 0) cnt[u][s] = cnt[u].size();
    ans[u]++;
    ans[u] -= cnt[u].size() - cnt[u][s];
    return to_string(cnt[u][s]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n);
    cnt.resize(n);
    ans.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    int best = 0;
    for (int i = 1; i < n; i++) {
        if (ans[i] > ans[best]) best = i;
    }
    cout << best + 1;
}