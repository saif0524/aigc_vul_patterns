#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int T;
    std::cin >> T;
    for(int i = 0; i < T; i++) {
        int n;
        std::cin >> n;
        double side = std::max(1.0 /std::sin(M_PI / n), 1.0 / std::cos(M_PI / n));
        std::cout << std::fixed << std::setprecision(9) << side << std::endl;
    }
    return 0;
}