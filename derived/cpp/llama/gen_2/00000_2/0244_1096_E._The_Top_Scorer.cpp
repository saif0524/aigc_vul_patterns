#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int mod = 998244353;

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long inverse(long long a) {
    return power(a, mod - 2);
}

long long comb(long long n, long long k, const vector<long long>& fac, const vector<long long>& ifac) {
    return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

int main() {
    int p, s, r;
    cin >> p >> s >> r;

    vector<long long> fac(5005, 1);
    for (int i = 1; i < 5005; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }

    vector<long long> ifac(5005, 1);
    ifac[5004] = inverse(fac[5004]);
    for (int i = 5003; i >= 0; i--) {
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
    }

    vector<vector<long long>> dp(s + 1, vector<long long>(p, 0));
    for (int i = 0; i <= s; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < p; i++) {
        for (int j = 0; j <= s; j++) {
            for (int k = 0; k <= j; k++) {
                dp[j][i] = (dp[j][i] + dp[k][i - 1]) % mod;
            }
        }
    }

    long long ans = 0;
    for (int i = r; i <= s; i++) {
        long long cnt = 0;
        for (int j = 0; j < i; j++) {
            cnt = (cnt + comb(p - 1 + j - 1, j, fac, ifac) * dp[s - i - j][p - 2]) % mod;
        }

        if (cnt == 0) {
            ans = (ans + dp[s - i][p - 1]) % mod;
        } else {
            ans = (ans + dp[s - i][p - 1] * inverse(p)) % mod;
        }
    }

    cout << ans << endl;

    return 0;
}