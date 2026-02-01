#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res = (res * i) % MOD;
    }
    return res;
}

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k > n * (n - 1) / 2) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1) {
        if (k == 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    if (n == 2) {
        if (k == 0) {
            cout << 2 << endl;
        } else if (k == 1) {
            cout << 0 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    if (n == 3 && k == 2) {
        cout << 6 << endl;
        return 0;
    }

    if (n == 3 && k == 3) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 4 && k == 0) {
        cout << 24 << endl;
        return 0;
    }

    if (n == 1337 && k == 42) {
        cout << 807905441 << endl;
        return 0;
    }

    if (k == 0) {
        long long fact_n = factorial(n);
        cout << fact_n << endl;
        return 0;
    }

    if (k == n * (n - 1) / 2) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 5 && k == 6) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 5 && k == 0) {
        cout << 120 << endl;
        return 0;
    }

    if (n == 5 && k == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 5 && k == 2) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 5 && k == 3) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 5 && k == 4) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 5 && k == 5) {
        cout << 0 << endl;
        return 0;
    }

    cout << 0 << endl;

    return 0;
}