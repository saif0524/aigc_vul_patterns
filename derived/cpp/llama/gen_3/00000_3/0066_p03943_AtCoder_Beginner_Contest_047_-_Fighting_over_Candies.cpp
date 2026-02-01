#include <iostream>
#include <algorithm>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int sum = a + b + c;
    if (sum % 2 != 0) {
        std::cout << "No" << std::endl;
        return 0;
    }

    int half = sum / 2;
    if (a == half || b == half || c == half ||
        a + b == half || a + c == half || b + c == half) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}