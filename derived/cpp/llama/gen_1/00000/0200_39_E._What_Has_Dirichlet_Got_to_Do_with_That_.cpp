#include <iostream>
#include <cstdio>

int pow(int a, int b) {
    int res = 1;
    for (int i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}

int main() {
    int a, b, n;
    std::cin >> a >> b >> n;

    if (pow(a, b) >= n && (pow(a + 1, b) >= n || pow(a, b + 1) >= n)) {
        std::cout << "Stas" << std::endl;
    } else if (pow(a + 1, b) < n && pow(a, b + 1) < n) {
        std::cout << "Masha" << std::endl;
    } else {
        std::cout << "Missing" << std::endl;
    }

    return 0;
}