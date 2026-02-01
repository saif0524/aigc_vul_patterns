#include <iostream>
#include <cmath>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    int minPeople = std::ceil((y * n) / 100.0);
    std::cout << std::max(0, minPeople - x) << std::endl;
    return 0;
}