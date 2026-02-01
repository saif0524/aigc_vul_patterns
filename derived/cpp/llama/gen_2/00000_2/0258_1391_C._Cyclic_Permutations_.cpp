#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;

long long fact[1000001];

long long pow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

long long inv(long long a) {
    return pow(a, mod - 2);
}

int main() {
    fact[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    int n;
    cin >> n;

    long long res = fact[n];
    for (int i = 1; i <= n; i++)
        res = (res - (fact[i - 1] * fact[n - i]) % mod + mod) % mod;

    cout << res << endl;
    return 0;
}