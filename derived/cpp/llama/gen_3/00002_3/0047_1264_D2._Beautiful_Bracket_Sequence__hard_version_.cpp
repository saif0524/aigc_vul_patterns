#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
using namespace std;

const long long mod = 998244353;

int main() {
    string a;
    cin >> a;

    vector<long long> fac(2000005, 1), inv(2000005, 1);
    for (int i = 2; i <= 2000000; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    inv[2000000] = 828542813;
    for (int i = 1999999; i >= 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }

    auto comb = [&](int n, int m) {
        if (m < 0 || m > n) {
            return 0ll;
        }
        return (fac[n] * inv[m] % mod) * inv[n - m] % mod;
    };

    int n = a.size();
    vector<long long> pow2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }

    long long ans = 0;
    for (int d = 1; d <= n; d++) {
        vector<vector<long long>> f(d + 1, vector<long long>(n + 1));
        vector<vector<long long>> g(d + 1, vector<long long>(n + 1));
        f[0][0] = 1;
        g[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i - 1]!= ')') {
                for (int j = 0; j <= d; j++) {
                    f[j][i] = (f[j][i] + f[j][i - 1]) % mod;
                    if (j > 0) {
                        f[j][i] = (f[j][i] + f[j - 1][i - 1]) % mod;
                    }
                }
            }
            if (a[i - 1]!= '(') {
                for (int j = 0; j <= d; j++) {
                    g[j][i] = (g[j][i] + g[j][i - 1]) % mod;
                    if (j > 0) {
                        g[j][i] = (g[j][i] + g[j - 1][i - 1]) % mod;
                    }
                }
            }
        }
        long long sum = 0;
        for (int i = 0; i <= d; i++) {
            sum = (sum + f[i][n] * g[d - i][n]) % mod;
        }
        ans = (ans + sum * d) % mod;
    }
    cout << ans << endl;

    return 0;
}