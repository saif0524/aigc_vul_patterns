#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int MOD = 998244353;

long long modPow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long modInv(long long a) {
    return modPow(a, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> dp(sum + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= sum; i++) {
        long long p = i * modInv(sum) % MOD;
        long long q = (n - 1) * modInv(n) % MOD;
        dp[i] = (1 + p * q % MOD * dp[i - 1] % MOD + (1 - p) * q % MOD * dp[i] % MOD) * modInv(1 - p * q % MOD) % MOD;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + dp[sum - a[i]]) % MOD;
    }

    cout << ans << endl;

    return 0;
}