#include <iostream>
#include <vector>
#include <cstdint>

const int64_t MOD = 1e9 + 7;

int64_t calculateXorSum(int64_t n, const std::vector<int64_t>& a) {
    int64_t result = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            result = (result + (a[i] ^ a[j])) % MOD;
        }
    }
    return result;
}

int main() {
    int64_t n;
    std::cin >> n;
    std::vector<int64_t> a(n);
    for (int64_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::cout << calculateXorSum(n, a) << std::endl;
    return 0;
}