#include <iostream>
#include <cstdint>

const int64_t MOD = 1000000007;

int64_t pow(int64_t x, int64_t n) {
    int64_t result = 1;
    while (n > 0) {
        if (n & 1) {
            result = (result * x) % MOD;
        }
        x = (x * x) % MOD;
        n >>= 1;
    }
    return result;
}

int main() {
    int64_t N;
    std::cin >> N;
    int64_t M = (N + 1) / 2;
    int64_t result = (pow(3, M) + MOD - pow(3, (N + 1) / 2)) % MOD;
    if (N % 2 == 0) {
        result = (result + pow(3, M)) % MOD;
    }
    std::cout << result << std::endl;
    return 0;
}