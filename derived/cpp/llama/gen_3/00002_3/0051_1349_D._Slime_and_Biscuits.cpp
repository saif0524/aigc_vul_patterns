#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

long long powmod(long long a, long long b) {
    long long res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return powmod(a, mod - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<long long> dp(sum + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= sum; i++) {
        long long p = i * inv(sum) % mod;
        long long q = (sum - i) * inv(sum) % mod;
        long long r = (n - 1) * inv(n) % mod;
        dp[i] = (p * (dp[i - 1] + 1) % mod + (q * r % mod * (dp[i - 1] + 1) % mod + q * (1 - r) % mod * (dp[i] + 1) % mod)) % mod;
        dp[i] = dp[i] * inv((1 - q * (1 - r) % mod + mod) % mod) % mod;
    }
    cout << dp[sum] << endl;
    return 0;
}