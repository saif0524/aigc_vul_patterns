#include <iostream>
#include <string>
#include <unordered_map>

const int MOD = 1e9 + 7;

std::unordered_map<int, int> cache;

int dp(int d, int m) {
    if (m == 0) return 1;
    if (cache.find(d * 10 + m) != cache.end()) return cache[d * 10 + m];
    if (d == 9) return cache[d * 10 + m] = (dp(1, m - 1) + dp(0, m - 1)) % MOD;
    return cache[d * 10 + m] = dp(d + 1, m - 1);
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    int ans = 0;
    while (n > 0) {
        ans = (ans + dp(n % 10, m)) % MOD;
        n /= 10;
    }
    std::cout << ans << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}