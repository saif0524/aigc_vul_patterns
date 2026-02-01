#include <iostream>

int main() {
    int n, m, x;
    std::cin >> n >> m >> x;

    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i + j) % 2 == 1) {
                int layer = std::min(std::min(i, j), std::min(n - i - 1, m - j - 1));
                if (layer == x - 1) {
                    ++result;
                }
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}