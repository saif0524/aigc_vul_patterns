#include <iostream>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int dx = (x2 - x1) / 2 + 1;
    int dy = y2 - y1 + 1;

    if ((x1 + y1) % 2 == 0) {
        std::cout << dx * dy << std::endl;
    } else {
        std::cout << dx * dy - (dx / 2) * ((dy + 1) / 2) - (dx / 2) * (dy / 2) << std::endl;
    }

    return 0;
}