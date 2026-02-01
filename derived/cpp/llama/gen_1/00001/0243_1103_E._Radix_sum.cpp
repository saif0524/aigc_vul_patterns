#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const unsigned long long mod = (1ULL << 58);

unsigned long long powmod(unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<unsigned long long> dp(10 * n + 1);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        vector<unsigned long long> ndp(10 * n + 1);
        for (int j = 0; j <= 10 * n; j++) {
            for (int k : a) {
                int d = (j + k) % 10;
                ndp[d] += dp[j];
                if (ndp[d] >= mod) {
                    ndp[d] -= mod;
                }
            }
        }
        swap(dp, ndp);
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i] << "\n";
    }

    return 0;
}