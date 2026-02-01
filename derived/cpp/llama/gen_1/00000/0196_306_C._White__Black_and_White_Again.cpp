#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000009;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

long long inverse_factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * (MOD - (MOD / i) * inverse_factorial(MOD % i) % MOD)) % MOD;
    }
    return result;
}

long long choose(int n, int k) {
    return (factorial(n) * inverse_factorial(k) % MOD * inverse_factorial(n - k) % MOD) % MOD;
}

long long solve(int n, int w, int b) {
    long long result = 0;
    for (int x = 1; x <= n - 2; x++) {
        for (int y = 1; y <= n - x; y++) {
            result = (result + choose(n - 1, x + y - 1) * choose(x + y - 1, y - 1) % MOD * choose(w - 1, x - 1) % MOD * choose(b - 1, y - 1) % MOD * factorial(w) % MOD * factorial(b) % MOD) % MOD;
        }
    }
    return result;
}

int main() {
    int n, w, b;
    cin >> n >> w >> b;
    cout << solve(n, w, b);
    return 0;
}