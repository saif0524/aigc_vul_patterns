#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0;
    } else {
        long long result = 8 * n;
        std::cout << result;
    }
}