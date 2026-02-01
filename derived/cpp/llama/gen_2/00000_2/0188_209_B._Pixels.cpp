#include <iostream>
#include <algorithm>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int sum = a + b + c - std::max({a, b, c});
    std::cout << sum << std::endl;

    return 0;
}