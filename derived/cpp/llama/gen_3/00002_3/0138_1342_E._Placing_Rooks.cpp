#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 998244353;

long long powMod(long long a, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return powMod(a * a % MOD, n / 2);
    return powMod(a * a % MOD, n / 2) * a % MOD;
}

long long inverse(long long a) {
    return powMod(a, MOD - 2);
}

long long binomialCoeff(long long n, long long k) {
    long long result = 1;
    for (long long i = 1; i <= k; i++) {
        result = result * (n - i + 1) % MOD * inverse(i) % MOD;
    }
    return result;
}

int main() {
    long long n, k;
    cin >> n >> k;

    if (k > n * (n - 1) / 2) {
        cout << 0 << endl;
        return 0;
    }

    if (k == 0) {
        long long result = 1;
        for (long long i = 1; i <= n; i++) {
            result = result * i % MOD;
        }
        cout << result << endl;
        return 0;
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    long long result = 0;
    for (long long p = 1; p <= min(n - 1, k); p++) {
        if (k - p > (n - p - 1) * (n - p) / 2) continue;
        result = (result + binomialCoeff(n, p) * binomialCoeff(n - p, k - p) % MOD * binomialCoeff(k - p + p - 1, p - 1) % MOD) % MOD;
    }

    for (long long i = 1; i <= n; i++) {
        result = result * i % MOD;
    }

    cout << result << endl;
    return 0;
}