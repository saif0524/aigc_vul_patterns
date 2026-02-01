#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    bool found = false;
    for (int i = 0; i <= c / a; ++i) {
        int remainder = c - i * a;
        if (remainder % b == 0 && remainder / b >= 0) {
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}