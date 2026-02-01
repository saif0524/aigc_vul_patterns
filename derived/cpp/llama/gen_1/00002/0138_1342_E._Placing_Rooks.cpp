#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

long long powMod(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return powMod(a, MOD - 2);
}

long long C(int n, int k, const vector<long long>& fact, const vector<long long>& invFact) {
    return ((fact[n] * invFact[k]) % MOD * invFact[n - k]) % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> fact(n + 1, 1);
    vector<long long> invFact(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = inv(fact[i]);
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = (dp[i] + dp[j] * dp[i - 1 - j] % MOD * fact[i - 1] % MOD * C(i - 1, j, fact, invFact) % MOD * C(n - i, i - 1 - j, fact, invFact)) % MOD;
        }
    }

    vector<vector<long long>> dp2(n + 1, vector<long long>(n + 1, 0));
    dp2[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int x = 0; x <= i - 1; x++) {
                dp2[i][j] = (dp2[i][j] + dp2[i - 1][x] * fact[i - 1] % MOD * C(i - 1, x, fact, invFact) % MOD * C(n - i, i - 1 - x, fact, invFact) % MOD * (j == 0 ? 0 : C(i - 1, j - 1, fact, invFact))) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + dp2[n][i] * dp[i] % MOD * inv(fact[i]) % MOD * (i % 2 == 0 ? 1 : -1)) % MOD;
    }

    cout << (ans + MOD) % MOD << endl;
    return 0;
}