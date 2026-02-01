#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double A, B, C;
    std::cin >> A >> B >> C;

    if (A == 0 && B == 0 && C == 0) {
        std::cout << -1 << std::endl;
    } else if (A == 0 && B == 0 && C != 0) {
        std::cout << 0 << std::endl;
    } else if (A == 0 && B != 0) {
        std::cout << 1 << std::endl;
        std::cout << std::fixed << std::setprecision(10) << -C / B << std::endl;
    } else {
        double D = B * B - 4 * A * C;
        if (D < 0) {
            std::cout << 0 << std::endl;
        } else if (D == 0) {
            std::cout << 1 << std::endl;
            std::cout << std::fixed << std::setprecision(10) << -B / (2 * A) << std::endl;
        } else {
            std::cout << 2 << std::endl;
            double x1 = (-B - std::sqrt(D)) / (2 * A);
            double x2 = (-B + std::sqrt(D)) / (2 * A);
            if (x1 > x2) {
                std::swap(x1, x2);
            }
            std::cout << std::fixed << std::setprecision(10) << x1 << std::endl;
            std::cout << std::fixed << std::setprecision(10) << x2 << std::endl;
        }
    }

    return 0;
}