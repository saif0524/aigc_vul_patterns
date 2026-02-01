#include <iostream>
#include <cstdint>

const int64_t MOD = 1000000007;

int64_t solve(int64_t n) {
    int64_t result = 1;
    while (n > 0) {
        if (n & 1) {
            result = (result * 3) % MOD;
        } else {
            result = (result * 2) % MOD;
        }
        n /= 2;
    }
    return result % MOD;
}

int main() {
    int64_t n;
    std::cin >> n;
    std::cout << solve(n) << std::endl;
    return 0;
}