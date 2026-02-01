#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 1e9 + 7;

long long power(long long x, long long y) {
    long long res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

long long inv(long long x) {
    return power(x, MOD - 2);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int tmp = ~0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                tmp &= a[i];
                cnt++;
            }
        }
        if (tmp == 0) {
            if (cnt % 2 == 1) {
                ans += 1;
            } else {
                ans -= 1;
            }
        }
    }
    ans %= MOD;
    if (ans < 0) {
        ans += MOD;
    }
    std::cout << ans << std::endl;

    return 0;
}