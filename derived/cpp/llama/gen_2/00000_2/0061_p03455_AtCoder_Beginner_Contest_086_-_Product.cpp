#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    if ((a % 2 == 0) || (b % 2 == 0)) {
        std::cout << "Even" << std::endl;
    } else {
        std::cout << "Odd" << std::endl;
    }

    return 0;
}