#include <iostream>
#include <cmath>

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long pollardRho(long long n) {
    if (n % 2 == 0)
        return 2;
    long long x = 2;
    long long y = 2;
    long long d = 1;
    while (d == 1) {
        x = (x * x + 1) % n;
        y = (y * y + 1) % n;
        y = (y * y + 1) % n;
        d = gcd(std::abs(x - y), n);
    }
    if (d == n)
        return n;
    return std::min(d, n / d);
}

int main() {
    long long n, p;
    std::cin >> n >> p;
    long long ans = 1;
    while (p > 1) {
        long long d = pollardRho(p);
        while (p % d == 0) {
            p /= d;
        }
        ans = std::max(ans, d);
    }
    long long res = ans;
    while (res > 1 && n % res != 0) {
        res = res / pollardRho(res);
    }
    std::cout << res << std::endl;
    return 0;
}