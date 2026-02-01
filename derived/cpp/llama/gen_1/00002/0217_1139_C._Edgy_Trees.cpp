#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
const int maxk = 110;

vector<int> g[maxn];
vector<int> col[maxn];
int dp[maxk][maxn];
int rep[maxn];

int find(int x) {
    if (rep[x] == x) return x;
    return rep[x] = find(rep[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    rep[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        rep[i] = i;
    }

    for (int i = 1; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(v);
        g[v].push_back(u);
        col[u].push_back(c);
        col[v].push_back(c);
        if (c == 1) {
            merge(u, v);
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= k; i++) {
        int cur = 0;
        for (int j = 1; j <= n; j++) {
            cur = (cur + dp[i - 1][j]) % mod;
        }
        for (int j = 1; j <= n; j++) {
            dp[i][j] = cur;
            for (int x : g[j]) {
                if (find(j) != find(x)) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][x] + mod) % mod;
                }
            }
        }
    }

    int ans = 1;
    for (int i = 1; i <= k; i++) {
        ans = (ans * n) % mod;
    }

    int bad = 0;
    for (int i = 1; i <= n; i++) {
        bad = (bad + dp[k][i]) % mod;
    }

    ans = (ans - bad + mod) % mod;
    cout << ans << '\n';

    return 0;
}