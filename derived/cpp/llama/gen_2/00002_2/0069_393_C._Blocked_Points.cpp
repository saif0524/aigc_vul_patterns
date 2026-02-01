#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 4 * n << std::endl;
    }
    return 0;
}