#include <iostream>
#include <cmath>

int main() {
    int a, b, c;
    int rectangles = 0, rhombuses = 0;
    char comma;

    while (std::cin >> a >> comma >> b >> comma >> c) {
        if (a == b) {
            rhombuses++;
            if (a * a * 2 == c * c) {
                rectangles++;
            }
        } else if (a * a + b * b == c * c) {
            rectangles++;
        }
    }

    std::cout << rectangles << std::endl;
    std::cout << rhombuses << std::endl;

    return 0;
}