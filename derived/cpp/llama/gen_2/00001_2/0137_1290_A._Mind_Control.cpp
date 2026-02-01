#include <iostream>
#include <algorithm>
#include <climits>

const int MAXN = 3505;

int T, n, m, k, a[MAXN], ans;

int main() {
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        ans = 0;
        for (int i = 0; i <= k; i++) {
            int tmp = INT_MAX;
            for (int j = 0; j <= m - k - 1; j++) {
                tmp = std::min(tmp, std::max(a[i + j + 1], a[n - (k - i) - (m - k - 1 - j)]));
            }
            ans = std::max(ans, tmp);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}