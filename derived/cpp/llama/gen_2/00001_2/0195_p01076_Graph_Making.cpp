#include <iostream>

int main() {
    long long n, d;
    std::cin >> n >> d;

    if (d == 1) {
        std::cout << n * (n - 1) / 2 << std::endl;
    } else if (d == 2) {
        std::cout << n * (n - 1) / 2 - (n - 1) << std::endl;
    } else if (d == 3) {
        std::cout << n * (n - 1) / 2 - (n - 1) - (n - 2) << std::endl;
    } else {
        std::cout << n * (n - 1) / 2 - (n - 1) - (n - 2) << std::endl;
    }

    return 0;
}