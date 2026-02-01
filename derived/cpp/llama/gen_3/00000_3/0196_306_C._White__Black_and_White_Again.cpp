#include <iostream>
#include <vector>

const int MOD = 1000000009;

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * 1LL * i) % MOD;
    }
    return result;
}

int combination(int n, int k) {
    return (factorial(n) * 1LL * factorial(k)) % MOD;
}

int permutation(int n, int k) {
    return (factorial(n) * 1LL * factorial(k)) % MOD;
}

int main() {
    int n, w, b;
    std::cin >> n >> w >> b;

    int result = 0;
    for (int i = 1; i <= n - 2; ++i) {
        for (int j = 1; j <= n - i - 1; ++j) {
            int k = n - i - j;
            if (k >= 1 && i + j + k == n) {
                int coefficient = (factorial(i + j + k) * 1LL * factorial(w)) % MOD;
                coefficient = (coefficient * 1LL * factorial(b)) % MOD;
                coefficient = (coefficient * 1LL * factorial(w)) % MOD;
                coefficient = (coefficient * 1LL * combination(w + i - 1, i)) % MOD;
                coefficient = (coefficient * 1LL * combination(b + j - 1, j)) % MOD;
                coefficient = (coefficient * 1LL * combination(w + k - 1, k)) % MOD;
                result = (result + coefficient) % MOD;
            }
        }
    }

    std::cout << result << std::endl;
    return 0;
}