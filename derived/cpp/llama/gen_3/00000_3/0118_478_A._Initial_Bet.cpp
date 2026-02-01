#include <iostream>

int main() {
    int c1, c2, c3, c4, c5;
    std::cin >> c1 >> c2 >> c3 >> c4 >> c5;

    for (int b = 1; b <= 100; b++) {
        if (c1 + b >= b && c2 + b >= b && c3 + b >= b && c4 + b >= b && c5 + b >= b) {
            if ((c1 + b) + (c2 + b) + (c3 + b) + (c4 + b) + (c5 + b) == 5 * b) {
                std::cout << b << std::endl;
                return 0;
            }
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}