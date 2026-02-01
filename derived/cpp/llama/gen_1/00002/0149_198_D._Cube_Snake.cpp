#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int layer = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) layer = k;
                if (j == n - 1) std::cout << (k * n * n) + (i * n) + j + 1 << std::endl;
                else std::cout << (k * n * n) + (i * n) + j + 1 << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}