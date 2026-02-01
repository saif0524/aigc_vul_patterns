#include <iostream>
#include <cmath>

int main() {
    int R;
    std::cin >> R;
    double circumference = 2 * M_PI * R;
    std::cout.precision(40);
    std::cout << circumference << std::endl;
    return 0;
}