#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += std::abs(a[i] - i);
    }

    std::vector<std::pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = {std::abs(i - a[i]), i};
    }

    std::sort(b.rbegin(), b.rend());

    std::vector<bool> used(n, false);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!used[j] && b[i].second != j) {
                int tmp = a[b[i].second];
                a[b[i].second] = a[j];
                a[j] = tmp;
                used[b[i].second] = true;
                used[j] = true;
                break;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res += std::abs(a[i] - i);
    }

    std::cout << std::max(res, ans) << std::endl;

    return 0;
}