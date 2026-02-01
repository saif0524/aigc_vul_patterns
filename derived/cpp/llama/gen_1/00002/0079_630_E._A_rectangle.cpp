#include <iostream>

int main() {
    long long x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    long long width = (x2 - x1 + 1);
    long long height = (y2 - y1 + 1);

    if (width % 2 == 0) {
        std::cout << width * height / 2 * 3 << std::endl;
    } else {
        std::cout << width * height / 2 * 3 + height / 2 << std::endl;
    }

    return 0;
}