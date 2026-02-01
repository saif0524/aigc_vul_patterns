#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    int k = std::ceil(std::sqrt(n));
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if ((i + j - 2) % 4 < 2 && n > 0) {
                std::cout << i << " " << j << std::endl;
                --n;
            }
        }
    }

    return 0;
}