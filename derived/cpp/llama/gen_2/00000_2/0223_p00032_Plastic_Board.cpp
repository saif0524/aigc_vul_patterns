#include <iostream>
#include <cmath>

int main() {
    int rectangles = 0;
    int rhombuses = 0;

    while (true) {
        int a, b, c;
        if (!(std::cin >> a >> b >> c)) break;

        double d = sqrt(a * a + b * b);
        if (std::abs(d - c) < 1e-9) rectangles++;

        if (a == b) rhombuses++;
    }

    std::cout << rectangles << std::endl;
    std::cout << rhombuses << std::endl;

    return 0;
}