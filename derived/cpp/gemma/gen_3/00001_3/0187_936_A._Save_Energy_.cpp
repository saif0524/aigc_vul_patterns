#include <iostream>
#include <iomanip>

int main() {
    long long k, d, t;
    std::cin >> k >> d >> t;

    if (d >= k) {
        std::cout << std::fixed << std::setprecision(10) << (double)t << std::endl;
    } else {
        double time = 0.0;
        time += (double)k;
        double remaining = (double)t - (double)k;
        
        if (remaining <= 0) {
            std::cout << std::fixed << std::setprecision(10) << (double)t << std::endl;
            return 0;
        }

        time += (remaining / 2.0);
        
        
        
        std::cout << std::fixed << std::setprecision(10) << time << std::endl;
    }

    return 0;
}