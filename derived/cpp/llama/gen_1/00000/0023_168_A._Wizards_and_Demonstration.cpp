#include <iostream>
#include <math.h>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    int target = std::ceil((double)y * n / 100);
    std::cout << std::max(0, target - x) << std::endl;
    return 0;
}