#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double A, B, C;
    std::cin >> A >> B >> C;

    if (A == 0 && B == 0 && C == 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    if (A == 0 && B == 0) {
        if (C == 0) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
        return 0;
    }

    if (A == 0) {
        std::cout << 1 << std::endl;
        std::cout << -C / B << std::endl;
        return 0;
    }

    double D = B * B - 4 * A * C;

    if (D < 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    if (D == 0) {
        std::cout << 1 << std::endl;
        std::cout << std::fixed << std::setprecision(10) << -B / (2 * A) << std::endl;
        return 0;
    }

    std::cout << 2 << std::endl;
    std::cout << std::fixed << std::setprecision(10) << (-B - std::sqrt(D)) / (2 * A) << std::endl;
    std::cout << std::fixed << std::setprecision(10) << (-B + std::sqrt(D)) / (2 * A) << std::endl;

    return 0;
}