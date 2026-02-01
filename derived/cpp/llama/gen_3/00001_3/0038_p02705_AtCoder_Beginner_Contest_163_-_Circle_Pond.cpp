#include <iostream>
#include <cmath>

int main() {
    const double pi = std::acos(-1.0);
    int R;
    std::cin >> R;
    std::cout.precision(50);
    std::cout << 2 * pi * R << std::endl;
    return 0;
}