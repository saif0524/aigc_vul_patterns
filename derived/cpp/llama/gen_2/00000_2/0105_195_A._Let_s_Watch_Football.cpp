#include <iostream>
#include <cmath>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int t = std::ceil((double)(a * c) / b) - c;

    std::cout << t << std::endl;

    return 0;
}