#include <iostream>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        if (n < 8) {
            std::cout << "0\n";
        } else if (n % 2 == 0) {
            std::cout << "0\n";
        } else {
            long long result = 1;
            for (int i = n - 8; i >= 1; --i) {
                result *= i;
            }
            result *= 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
            std::cout << result << "\n";
        }
    }
    return 0;
}