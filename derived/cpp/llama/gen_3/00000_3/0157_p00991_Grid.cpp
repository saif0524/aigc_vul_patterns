#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 100000007;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return power(a, MOD - 2);
}

long long C(long long n, long long m, const vector<long long>& fac, const vector<long long>& invFac) {
    return fac[n] * invFac[m] % MOD * invFac[n - m] % MOD;
}

int main() {
    int r, c, a1, a2, b1, b2;
    cin >> r >> c >> a1 >> a2 >> b1 >> b2;

    vector<long long> fac(r * c + 1), invFac(r * c + 1);
    fac[0] = 1;
    for (int i = 1; i <= r * c; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    invFac[r * c] = inv(fac[r * c]);
    for (int i = r * c - 1; i >= 0; i--) {
        invFac[i] = invFac[i + 1] * (i + 1) % MOD;
    }

    int dx = abs(a1 - b1);
    int dy = abs(a2 - b2);

    int ans = 0;
    for (int i = 0; i <= min(dx, r - 1 - dx); i++) {
        for (int j = 0; j <= min(dy, c - 1 - dy); j++) {
            int x = dx - i + dy - j;
            int y = i + j;
            ans = (ans + C(x + y, x, fac, invFac)) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}