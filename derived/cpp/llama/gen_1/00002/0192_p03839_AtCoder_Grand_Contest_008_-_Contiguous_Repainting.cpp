#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }

    int ans = 0;
    for (int i = 0; i + k <= n; i++) {
        int s = sum[i + k] - sum[i];
        ans = std::max(ans, s);
    }

    std::cout << ans << std::endl;

    return 0;
}