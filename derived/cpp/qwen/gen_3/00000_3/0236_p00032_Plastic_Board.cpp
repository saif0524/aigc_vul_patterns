#include <iostream>
#include <cmath>

int main() {
    int a, b, c;
    int rectangles = 0, rhombuses = 0;

    while (std::cin >> a >> b >> c, a || b || c) {
        int max_side = std::max(a, b);
        int min_side = std::min(a, b);

        if (c * c == a * a + b * b) {
            rectangles++;
        } else if (a == b && c * c == 2 * a * a) {
            rhombuses++;
        }
    }

    std::cout << rectangles << std::endl;
    std::cout << rhombuses << std::endl;

    return 0;
}