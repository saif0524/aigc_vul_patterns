#include <iostream>
#include <vector>

int main() {
    int n, k, m;
    std::cin >> n >> k >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> counts(n, 0);
    for (int i = 0; i < n; ++i) {
        counts[i] = m;
    }

    int left = 0;
    int right = n - 1;
    while (left + 1 < n) {
        int count = std::min(counts[left], counts[right]);
        counts[left] -= count;
        counts[right] -= count;
        if (counts[left] == 0) {
            left++;
        }
        if (counts[right] == 0) {
            right--;
        }
    }

    for (int i = 0; i < n; ++i) {
        counts[i] = m;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        counts[i] = m;
    }
    for (int i = 0; i < n; ++i) {
        counts[i] %= k;
        ans += counts[i];
    }

    std::cout << ans << std::endl;
    return 0;
}