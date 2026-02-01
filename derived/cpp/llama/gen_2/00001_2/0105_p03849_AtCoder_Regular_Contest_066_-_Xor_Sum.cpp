#include <iostream>
#include <cstdint>

const int64_t MOD = 1e9 + 7;

int64_t powmod(int64_t base, int64_t exponent, int64_t mod) {
    int64_t result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % mod;
        }
        exponent >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int64_t n;
    std::cin >> n;

    int64_t bits = 0;
    while ((1LL << bits) <= n) {
        bits++;
    }

    int64_t ans = 0;
    for (int64_t i = 0; i <= bits; i++) {
        if ((1LL << i) <= n) {
            ans = (ans + (powmod(3, i, MOD) * powmod(2, bits - i, MOD))) % MOD;
        } else {
            int64_t remainder = n - (1LL << (i - 1)) + 1;
            ans = (ans + (remainder * powmod(2, bits - i, MOD))) % MOD;
            break;
        }
    }

    std::cout << ans << "\n";

    return 0;
}