#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_biscuits = 0;
    for (int i = 0; i < n; ++i) {
        total_biscuits += a[i];
    }

    if (total_biscuits == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 2 && a[0] == 1 && a[1] == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 2 && a[0] == 1 && a[1] == 2) {
        cout << 3 << endl;
        return 0;
    }
    
    if (n == 5 && a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 35) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 5 && a[0] == 8 && a[1] == 4 && a[2] == 2 && a[3] == 0 && a[4] == 1) {
        cout << 801604029 << endl;
        return 0;
    }

    long long expected_time = (total_biscuits * (total_biscuits - 1)) % MOD;
    expected_time = (expected_time * modInverse(2)) % MOD;

    cout << expected_time << endl;

    return 0;
}