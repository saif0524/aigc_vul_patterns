#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int MOD = 1e9 + 7;

long long pow_mod(long long x, int n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<long long> dp(M + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; ++i) {
        vector<long long> dp2(M + 1, 0);
        long long p = 1;
        for (int j = 0; j < M; ++j) {
            p = p * 2 % MOD;
            dp2[j + 1] = (dp2[j] + dp[j] * p) % MOD;
        }
        dp = dp2;
    }

    long long ans = 0;
    for (int i = 0; i <= M; ++i) {
        ans = (ans + dp[i] * pow_mod(pow_mod(2, N) - 1, M - i)) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}