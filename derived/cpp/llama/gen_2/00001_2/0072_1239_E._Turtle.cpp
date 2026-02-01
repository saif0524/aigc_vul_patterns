#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    std::vector<int> ans(2 * n);
    ans[0] = a[0];
    ans[2 * n - 1] = a[2 * n - 1];

    int idx = 1;
    for (int i = 1; i < n; ++i) {
        ans[i] = a[idx++];
    }

    for (int i = n; i < 2 * n - 1; ++i) {
        ans[i] = a[idx++];
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";

    for (int i = n; i < 2 * n; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";

    return 0;
}