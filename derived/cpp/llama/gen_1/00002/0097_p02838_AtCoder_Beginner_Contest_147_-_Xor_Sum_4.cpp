#include <iostream>
#include <vector>

const long long mod = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < 60; i++) {
        long long ones = 0;
        long long zeros = 0;
        long long temp = (1LL << i);

        for (int j = 0; j < n; j++) {
            if (a[j] & temp) {
                ones++;
            } else {
                zeros++;
            }
        }

        ans = (ans + (ones * zeros % mod * temp % mod)) % mod;
    }

    std::cout << ans << std::endl;

    return 0;
}