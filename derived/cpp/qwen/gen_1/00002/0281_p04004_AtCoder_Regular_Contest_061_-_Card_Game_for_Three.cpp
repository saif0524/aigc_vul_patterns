#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long mod_pow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, M, K;
    cin >> N >> M >> K;
    long long total = (N + M + K);
    long long ans = (3 * mod_pow(3, total - 1) - 2 * mod_pow(2, total) + mod_pow(1, total)) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}