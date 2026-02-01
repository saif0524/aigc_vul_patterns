#include <iostream>
#include <climits>

int main() {
    long long n, m, a, b, p, q;
    std::cin >> n >> m >> a >> b >> p >> q;

    long long minDistance = LLONG_MAX;

    for (long long k = 0; k < n; k++) {
        long long distance = (p * a * k + q * b * k) - m;
        if (distance < 0) continue;

        long long remainingDistance = distance % (a * p);
        if (remainingDistance <= m) {
            minDistance = std::min(minDistance, distance);
        }
    }

    if (minDistance == LLONG_MAX) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 1 << std::endl;
    }

    return 0;
}