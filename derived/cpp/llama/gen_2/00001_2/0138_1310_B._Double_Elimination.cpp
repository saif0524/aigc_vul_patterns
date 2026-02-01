#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int ans = 0;
    int x = 1;

    while (x < (1 << n)) {
        int l = 0, r = k - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] > x) r = mid;
            else l = mid + 1;
        }

        int g1 = l, g2 = k - l;
        ans += std::min(g1, g2) + g1;
        x *= 2;
    }

    if (k > 0) ans += 1;

    std::cout << ans << std::endl;

    return 0;
}