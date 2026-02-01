#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<long long>> w(n, std::vector<long long>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                w[i][j] = 0;
            } else if (i < j) {
                long long val = (1LL << (i + j)) + i * j;
                w[i][j] = val;
                w[j][i] = val;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << w[i][j];
            if (j != n - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}