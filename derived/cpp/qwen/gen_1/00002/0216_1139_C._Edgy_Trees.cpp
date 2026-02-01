#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

constexpr int MAXN = 1e5 + 10;

vector<piii> adj[MAXN];
int dp[MAXN][105];
int dp2[MAXN][105];

void dfs(int u, int p) {
    dp[u][0] = 1;
    for (auto [edge, v] : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i = 1; i <= 100; ++i) {
            if (edge.first) {
                dp2[u][i] = (dp2[u][i] + dp[v][i - 1]) % MOD;
            } else {
                dp[u][i] = (dp[u][i] + dp[v][i - 1]) % MOD;
            }
        }
    }
    for (int i = 1; i <= 100; ++i) {
        dp[u][i] = (dp[u][i] + dp2[u][i]) % MOD;
    }
}

void dfs2(int u, int p, int p_sum) {
    for (auto [edge, v] : adj[u]) {
        if (v == p) continue;
        int new_p_sum = p_sum + dp[u][100];
        if (edge.first) new_p_sum = (new_p_sum - dp[v][100] + MOD) % MOD;
        else new_p_sum = (new_p_sum - dp2[v][100] + MOD) % MOD;
        dfs2(v, u, new_p_sum);
    }
    for (int i = 100; i >= 1; --i) {
        dp[u][i] = (dp[u][i] + dp[u][i - 1]) % MOD;
        dp2[u][i] = (dp2[u][i] + dp2[u][i - 1]) % MOD;
    }
    for (auto [edge, v] : adj[u]) {
        if (v == p) continue;
        int res = (dp[u][100] + p_sum) % MOD;
        if (edge.first) {
            res = (res - dp2[v][100] + MOD) % MOD;
        } else {
            res = (res - dp[v][100] + MOD) % MOD;
        }
        res = (res - dp[v][100] + MOD) % MOD;
        dp[v][100] = (dp[v][100] + res) % MOD;
        if (edge.first) {
            dp2[v][100] = (dp2[v][100] + res) % MOD;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({{c, v}, v});
        adj[v].push_back({{c, u}, u});
    }
    dfs(1, -1);
    dfs2(1, -1, 0);

    int total = 0;
    for(int i = 1; i <= n; i++){
        total = (total + dp[i][k] + dp2[i][k]) % MOD;
    }

    int all_sequences = 1;
    for(int i = 0; i < k; i++){
        all_sequences = (1LL * all_sequences * n) % MOD;
    }

    int ans = (all_sequences - total + MOD) % MOD;
    cout << ans;
    return 0;
}