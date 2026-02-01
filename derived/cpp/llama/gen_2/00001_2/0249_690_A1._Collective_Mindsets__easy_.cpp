#include <iostream>

int main() {
    int N;
    std::cin >> N;

    if (N == 1) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << (N + 1) / 2 << std::endl;
    }

    return 0;
}