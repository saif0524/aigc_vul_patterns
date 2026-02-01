#include <iostream>
#include <vector>

int main() {
    int n, k, d;
    std::cin >> n >> k >> d;

    if (k == 1 || (k == 2 && n > 2 && d == 1) || (k == 2 && n > 3 && d > 1)) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> result(d, std::vector<int>(n, 0));
    for (int i = 0; i < d; ++i) {
        int cnt = 1;
        for (int j = 0; j < n; ++j) {
            result[i][j] = cnt;
            if (cnt == k) {
                cnt = 1;
            } else {
                if (i > 0 && result[i - 1][j] == cnt) {
                    ++cnt;
                }
            }
        }
    }

    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}