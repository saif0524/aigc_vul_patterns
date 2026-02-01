#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int dp[N], d[N];

void dfs(int v) {
    if (d[v] == 1) return;
    d[v] = 1;
    for (auto u : g[v]) {
        dfs(u);
        if (dp[u] == 0) dp[v] = 1;
        else if (dp[u] == -1) dp[v] = -1;
        else if (dp[u] == 1) {
            if (dp[v] != -1) dp[v] = 0;
        }
    }
    if (dp[v] != -1) dp[v] = d[v] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        g[i].resize(k);
        for (auto &j : g[i]) {
            cin >> j;
            j--;
        }
    }
    int s;
    cin >> s;
    s--;
    for (int i = 0; i < n; ++i) {
        dp[i] = -1;
        d[i] = 0;
    }
    dfs(s);
    if (dp[s] == 1) {
        cout << "Win\n";
        vector<int> p;
        function<void(int)> print = [&](int v) {
            p.push_back(v);
            if (dp[v] == 0) return;
            for (auto u : g[v]) {
                if (dp[u] == 0) {
                    print(u);
                    return;
                }
            }
        };
        print(s);
        for (auto &i : p) cout << i + 1 << ' ';
        cout << '\n';
    } else if (dp[s] == 0) {
        cout << "Draw\n";
    } else {
        cout << "Lose\n";
    }
    return 0;
}