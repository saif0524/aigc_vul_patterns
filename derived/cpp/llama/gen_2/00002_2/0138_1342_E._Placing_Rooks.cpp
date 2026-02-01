#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MOD = 998244353;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long inverse(long long a) {
    return power(a, MOD - 2);
}

long long C(int n, int k) {
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = (res * (n - i + 1)) % MOD;
        res = (res * inverse(i)) % MOD;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k > n * (n - 1) / 2) {
        cout << 0 << endl;
        return 0;
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i * (i - 1) / 2 > k) {
            break;
        }
        int j = n - i;
        if (j * (j - 1) / 2 < k - i * (i - 1) / 2) {
            continue;
        }
        long long ways = C(n, i) * C(n - i, j) % MOD;
        ways = ways * power(i, i) % MOD;
        ways = ways * power(j, j) % MOD;
        ways = ways * power(2, k - i * (i - 1) / 2) % MOD;
        ways = ways * power(inverse(i), k - i * (i - 1) / 2) % MOD;
        ans = (ans + ways) % MOD;
    }

    cout << ans << endl;

    return 0;
}