#include <iostream>
#include <cmath>

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    long long n;
    std::cin >> n;
    long long ans = 0;
    while (n > 0) {
        for (long long i = 2; i <= n; i++) {
            if (n % i == 0 && isPrime(i)) {
                n -= i;
                ans++;
                break;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}