#include <iostream>
#include <algorithm>

int main() {
    long long n, p, w, d;
    std::cin >> n >> p >> w >> d;

    for (long long y = 0; y <= n; y++) {
        long long tmp = p - y * d;
        if (tmp < 0) break;
        if (tmp % w == 0) {
            long long x = tmp / w;
            if (x + y <= n) {
                std::cout << x << " " << y << " " << n - x - y << std::endl;
                return 0;
            }
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}