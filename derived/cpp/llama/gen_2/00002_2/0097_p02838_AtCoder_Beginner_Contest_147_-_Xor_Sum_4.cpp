#include <iostream>
#include <vector>
#include <cstdint>

const int64_t MOD = 1e9 + 7;

int64_t calculateXorSum(const std::vector<int64_t>& A) {
    int64_t result = 0;
    for (int i = 0; i < 60; ++i) {
        int64_t count = 0;
        int64_t countWithBit = 0;
        for (int64_t a : A) {
            if (a & (1LL << i)) {
                countWithBit++;
            }
            count += countWithBit;
        }
        int64_t countWithoutBit = A.size() - countWithBit;
        result = (result + (countWithoutBit * countWithBit % MOD) * (1LL << i) % MOD) % MOD;
    }
    return result;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    int64_t result = calculateXorSum(A);
    std::cout << result << std::endl;
    return 0;
}