#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

const int N = 42, M = 1000005;
ll dp[N][M];

int main() {
    int n, k, c, t;
    cin >> n >> k >> c >> t;

    vector<int> a(k), b(k), w(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i] >> b[i] >> w[i];
    }

    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = t; j >= 0; j--) {
            for (int l = n - 1; l >= 0; l--) {
                if (j + w[i] <= t && l + b[i] <= n) {
                    (dp[l + b[i]][j + w[i]] += dp[l][j]) %= mod;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= t; i++) {
        if (c + i <= n) {
            (ans += dp[c + i][t]) %= mod;
        }
    }

    cout << ans << "\n";
    return 0;
}