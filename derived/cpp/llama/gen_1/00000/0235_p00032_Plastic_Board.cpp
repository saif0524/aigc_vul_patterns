#include <iostream>
#include <cmath>

int main() {
    int rectangles = 0;
    int rhombuses = 0;

    while (true) {
        int a, b, c;
        if (!(std::cin >> a >> b >> c)) break;

        if (a * a + b * b == c * c) rectangles++;
        if (a == b) rhombuses++;
    }

    std::cout << rectangles << std::endl;
    std::cout << rhombuses << std::endl;

    return 0;
}