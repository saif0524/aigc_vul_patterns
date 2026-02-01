#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int k;
    std::cin >> k;

    std::vector<int> c(k);
    for (int i = 0; i < k; i++) {
        std::cin >> c[i];
    }

    std::vector<long long> fact(1001, 1);
    for (int i = 1; i <= 1000; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    long long ans = 1;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        ans = (ans * fact[sum + c[i] - 1]) % MOD;
        ans = (ans * modInverse(fact[c[i] - 1], MOD)) % MOD;
        ans = (ans * modInverse(fact[sum], MOD)) % MOD;
        sum += c[i];
    }

    std::cout << ans << std::endl;

    return 0;
}

long long power(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

long long modInverse(long long a, long long m) {
    return power(a, m - 2, m);
}