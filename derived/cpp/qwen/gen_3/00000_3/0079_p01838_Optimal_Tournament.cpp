#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int max_pairwise_diff = 0;
    for (int i = 0; i <= n - k; ++i) {
        max_pairwise_diff = std::max(max_pairwise_diff, a[i + k - 1] - a[i]);
    }
    std::cout << max_pairwise_diff;
    return 0;
}