#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> pow2(N + 1);
    pow2[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    vector<long long> dp(M + 1);
    dp[0] = 1;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = (dp[i] + dp[j] * dp[i - j - 1] % MOD * pow2[j * (N - 1) + (i - j - 1)] % MOD) % MOD;
        }
    }

    long long ans = dp[M];
    for (int i = 1; i <= M; i++) {
        ans = ans * modpow(2, N) % MOD;
    }

    cout << ans << endl;

    return 0;
}