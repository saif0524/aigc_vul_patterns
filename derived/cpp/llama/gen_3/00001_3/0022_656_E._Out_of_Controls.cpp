#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<int>> d(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = a[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = std::max(ans, d[i][j]);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}