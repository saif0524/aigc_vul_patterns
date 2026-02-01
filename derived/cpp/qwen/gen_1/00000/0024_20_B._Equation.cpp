#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    
    if (A == 0) {
        if (B == 0) {
            if (C == 0) std::cout << -1;
            else std::cout << 0;
        } else {
            std::cout << 1 << std::endl;
            std::cout << std::fixed << std::setprecision(10) << -static_cast<double>(C) / B;
        }
    } else {
        long long discriminant = static_cast<long long>(B) * B - 4LL * A * C;
        if (discriminant < 0) {
            std::cout << 0;
        } else if (discriminant == 0) {
            std::cout << 1 << std::endl;
            std::cout << std::fixed << std::setprecision(10) << -static_cast<double>(B) / (2 * A);
        } else {
            double root1 = (-B + std::sqrt(discriminant)) / (2.0 * A);
            double root2 = (-B - std::sqrt(discriminant)) / (2.0 * A);
            std::vector<double> roots = {root1, root2};
            std::sort(roots.begin(), roots.end());
            std::cout << 2 << std::endl;
            std::cout << std::fixed << std::setprecision(10) << roots[0] << std::endl;
            std::cout << std::fixed << std::setprecision(10) << roots[1];
        }
    }
    return 0;
}