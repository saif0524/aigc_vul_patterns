#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        n *= 2;
        double angle = 2 * M_PI / n;
        double apothem = 1 / (2 * std::tan(M_PI / n));
        double sideLength = 2 * apothem + 1;
        std::cout.precision(10);
        std::cout << std::fixed << sideLength << std::endl;
    }
    return 0;
}