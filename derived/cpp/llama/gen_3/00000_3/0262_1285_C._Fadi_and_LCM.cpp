#include <iostream>
#include <cmath>

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    long long x;
    std::cin >> x;

    long long a = 1;
    long long b = x;

    for (long long i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            long long j = x / i;
            if (gcd(i, j) == 1) {
                if (std::max(i, j) < std::max(a, b)) {
                    a = i;
                    b = j;
                }
            }
        }
    }

    std::cout << a << " " << b << std::endl;

    return 0;
}