#include <iostream>
#include <cmath>

const double PI = std::acos(-1.0);

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        double side = std::sin(PI / n) * 2 / std::sin(PI / (2 * n));
        std::cout << side << std::endl;
    }

    return 0;
}