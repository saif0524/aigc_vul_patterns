#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n;
string s;
vector<vector<int>> dp;

int dfs(int pos, int k, int mask) {
    if (k == 0) return (mask == (1 << (n + 1)) - 1) ? 1 : 0;
    if (pos >= n) return 0;
    if (dp[pos][mask] != -1) return dp[pos][mask];

    int res = 0;
    int num = 0;
    for (int i = pos; i < n; i++) {
        num = num * 2 + (s[i] - '0');
        if (num > 0 && (mask & (1 << (i + 1))) == 0) {
            res = (res + dfs(i + 1, k - 1, mask | (1 << (i + 1)))) % MOD;
        }
    }
    return dp[pos][mask] = res;
}

int f(int k) {
    return dfs(0, k, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    dp.resize(n + 1, vector<int>(1 << (n + 1), -1));

    int res = 0;
    for (int k = 2; k <= n + 1; k++) {
        res = (res + f(k)) % MOD;
    }
    cout << res << '\n';
    return 0;
}