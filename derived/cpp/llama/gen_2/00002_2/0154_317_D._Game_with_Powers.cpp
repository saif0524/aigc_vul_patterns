#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    if (n == 1 || (n & (n - 1)) == 0) {
        std::cout << "Vasya" << std::endl;
    } else {
        std::cout << "Petya" << std::endl;
    }

    return 0;
}