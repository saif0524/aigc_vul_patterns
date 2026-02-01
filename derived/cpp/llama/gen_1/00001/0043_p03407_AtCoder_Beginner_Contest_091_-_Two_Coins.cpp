#include <iostream>
#include <algorithm>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    for (int x = 0; x <= C / A; x++) {
        if ((C - A * x) % B == 0 && (C - A * x) / B >= 0) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }

    std::cout << "No" << std::endl;
    return 0;
}