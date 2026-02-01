#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;

const int MAX_N = 105;
const int MAX_M = 105;
const int MAX_K = 105;

ll dp[MAX_N][MAX_M][MAX_K];
ll grid[MAX_N][MAX_M];

ll cnt[MAX_N + MAX_M - 1][MAX_K];

ll powMod(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, d;
    cin >> n >> m >> k >> d;

    for (int i = 1; i <= n + m - 1; ++i) {
        for (int j = 1; j <= k; ++j) {
            cnt[i][j] = (cnt[i][j - 1] + powMod(j, i, d)) % d;
        }
    }

    ll ans = 0;
    for (int mask = 0; mask < (1 << (n + m - 1)); ++mask) {
        ll val = 1;
        for (int i = 1; i <= n + m - 1; ++i) {
            if (mask & (1 << (i - 1))) {
                val = (val * cnt[i][k]) % d;
            } else {
                val = (val * k) % d;
            }
        }
        if (__builtin_popcount(mask) & 1) {
            ans = (ans - val + d) % d;
        } else {
            ans = (ans + val) % d;
        }
    }

    cout << (ans * powMod(k, n * m, d)) % d << '\n';

    return 0;
}