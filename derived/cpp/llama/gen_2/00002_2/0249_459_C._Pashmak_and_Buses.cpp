#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k, d;
    std::cin >> n >> k >> d;

    if (k == 1 && n > 1) {
        std::cout << -1 << std::endl;
        return 0;
    }

    if (k < n && d == 1) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> ans(d, std::vector<int>(n, 0));

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = (j + i) % k + 1;
        }
    }

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << ans[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}