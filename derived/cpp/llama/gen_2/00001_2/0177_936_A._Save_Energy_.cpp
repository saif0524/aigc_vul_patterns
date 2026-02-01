#include <iostream>
#include <iomanip>

int main() {
    long long k, d, t;
    std::cin >> k >> d >> t;

    double x = (double)t * k / (2 * k + d);

    if (x <= t) {
        std::cout << std::fixed << std::setprecision(10) << t << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(10) << t * (k + d) / (2 * k + d) << std::endl;
    }

    return 0;
}