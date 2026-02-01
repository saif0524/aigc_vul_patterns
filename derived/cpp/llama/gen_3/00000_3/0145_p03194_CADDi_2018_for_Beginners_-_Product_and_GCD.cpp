#include <iostream>
#include <cmath>

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long max_gcd(long long n, long long p) {
    long long ans = 1;
    for (long long i = 2; i * i <= p; i++) {
        if (p % i == 0) {
            long long cnt = 0;
            while (p % i == 0) {
                p /= i;
                cnt++;
            }
            cnt %= n;
            while (cnt > 0) {
                ans *= i;
                cnt--;
            }
        }
    }
    if (p > 1) {
        long long cnt = n - 1;
        while (cnt > 0) {
            ans *= p;
            cnt--;
        }
    }
    return ans;
}

int main() {
    long long n, p;
    std::cin >> n >> p;
    std::cout << max_gcd(n, p);
    return 0;
}