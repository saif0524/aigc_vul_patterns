#include <iostream>
#include <vector>
#include <bitset>

const long long mod = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long ans = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                cnt ^= a[i];
            }
        }
        if (!cnt) {
            ans = (ans + 1) % mod;
        }
    }

    std::cout << ans << '\n';

    return 0;
}