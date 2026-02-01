#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int distance = std::abs(a - b);
    int sum = 0;

    for (int i = 1; i <= distance; i++) {
        sum += i;
    }

    std::cout << sum << std::endl;

    return 0;
}