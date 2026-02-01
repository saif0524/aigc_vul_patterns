#include <iostream>
#include <vector>

const long long MOD = 1000000007;

int main() {
    int n, m;
    std::cin >> n >> m;

    long long res = 0;
    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            for (int t = l; t <= r; ++t) {
                for (int a = 1; a <= m; ++a) {
                    for (int b = a + 1; b <= m; ++b) {
                        res = (res + 1LL * (n - r + 1) * (r - t + 1) * (t - l + 1) * (a - 1) * (m - b)) % MOD;
                    }
                }
            }
        }
    }

    std::cout << res << std::endl;

    return 0;
}