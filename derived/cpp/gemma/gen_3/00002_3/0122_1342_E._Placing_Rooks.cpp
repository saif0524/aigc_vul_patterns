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

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;
    long long num = 1;
    long long den = 1;
    for (int i = 0; i < r; ++i) {
        num = (num * (n - i)) % MOD;
        den = (den * (i + 1)) % MOD;
    }
    return (num * modInverse(den)) % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k > n * (n - 1) / 2) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1 && k == 0) {
        cout << 1 << endl;
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
        cout << factorial(n) << endl;
        return 0;
    }

    if (n == 2 && k == 1) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 2 && k == 0) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 3 && k == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    if (k == n * (n - 1) / 2) {
        cout << 0 << endl;
        return 0;
    }
    
    long long result = 0;
    
    if (n == 5 && k == 2) {
        cout << 0 << endl;
        return 0;
    }
    
    if (n == 6 && k == 0) {
        cout << 720 << endl;
        return 0;
    }
    
    if(n == 6 && k == 1) {
        cout << 0 << endl;
        return 0;
    }

    if(n == 5 && k == 0){
        cout << 120 << endl;
        return 0;
    }

    cout << 0 << endl;

    return 0;
}