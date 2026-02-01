#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0;
    } else {
        long long result = 8 * (n - 1);
        std::cout << result;
    }
    return 0;
}