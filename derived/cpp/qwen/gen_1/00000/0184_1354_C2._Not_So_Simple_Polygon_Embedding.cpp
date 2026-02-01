#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        double angle = 3.14159265358979323846 / n;
        double side = 1 / cos(angle);
        std::cout << std::fixed << std::setprecision(9) << side << "\n";
    }
}