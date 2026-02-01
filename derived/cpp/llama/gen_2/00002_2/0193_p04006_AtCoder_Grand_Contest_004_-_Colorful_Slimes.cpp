#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

int main() {
    int N, X;
    std::cin >> N >> X;

    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::vector<long long> B(N);
    for (int i = 0; i < N; ++i) {
        B[i] = A[(i + N - 1) % N];
    }

    long long answer = LLONG_MAX;
    for (int i = 0; i < N; ++i) {
        long long sum = A[i];
        long long spell = 0;
        for (int j = 1; j < N; ++j) {
            long long minVal = LLONG_MAX;
            for (int k = j; k < N; ++k) {
                long long val = spell + B[(i + k) % N] + (k - j + 1) * X;
                minVal = std::min(minVal, val);
            }
            sum += minVal;
            spell += X;
        }
        answer = std::min(answer, sum);
    }

    std::cout << answer << std::endl;

    return 0;
}