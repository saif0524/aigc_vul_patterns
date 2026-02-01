#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n, r;
    std::cin >> n >> r;

    std::vector<long long> c(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        std::cin >> c[i];
    }

    std::cout.precision(10);
    std::cout << static_cast<double>(c[0] + c[1] + c[2] + c[3]) / 4.0 << std::endl;

    for (int i = 0; i < r; ++i) {
        int z, g;
        std::cin >> z >> g;
        c[z] = g;

        long long sum = 0;
        for (int j = 0; j < (1 << n); ++j) {
            sum += c[j];
        }

        std::cout << static_cast<double>(sum) / (1 << n) << std::endl;
    }

    return 0;
}