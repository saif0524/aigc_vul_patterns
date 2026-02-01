#include <iostream>
#include <iomanip>

int main() {
    int n;
    while (std::cin >> n && n!= 0) {
        double ans = 0.0;
        double p = 1.0;
        for (int i = 0; i < n; ++i) {
            ans += p;
            p /= 2.0;
        }
        std::cout << std::fixed << std::setprecision(8) << ans << std::endl;
    }
    return 0;
}