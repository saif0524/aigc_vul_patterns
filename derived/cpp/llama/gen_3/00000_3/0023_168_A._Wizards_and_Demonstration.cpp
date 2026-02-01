#include <iostream>
#include <cmath>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;

    double required = std::ceil((double)n * y / 100);
    int clones = std::max(0, (int)required - x);

    std::cout << clones << std::endl;

    return 0;
}