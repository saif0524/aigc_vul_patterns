#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int t = (a * c - 1) / b + 1 - c;
    if (t < 0) t = 0;

    std::cout << t << std::endl;

    return 0;
}