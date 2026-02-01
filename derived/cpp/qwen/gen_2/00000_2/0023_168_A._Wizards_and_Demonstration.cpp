#include <iostream>
#include <cmath>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    
    int required_people = std::ceil(static_cast<double>(y) / 100 * n);
    int clones = std::max(0, required_people - x);
    
    std::cout << clones << std::endl;
    
    return 0;
}