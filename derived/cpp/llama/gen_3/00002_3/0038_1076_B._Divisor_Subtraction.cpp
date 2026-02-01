#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;

    long long ans = 0;
    while (n > 0) {
        for (long long i = 2; i <= std::sqrt(n); i++) {
            if (n % i == 0) {
                ans++;
                n -= i;
                break;
            }
        }
        if (n > 0 && n <= std::sqrt(n)) {
            ans++;
            n = 0;
        }
    }
    std::cout << ans;
    return 0;
}