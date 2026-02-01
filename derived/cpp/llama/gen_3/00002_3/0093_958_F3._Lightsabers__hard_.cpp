#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int mod = 1009;

long long power(long long x, int y) {
    long long res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, mod - 2);
}

long long nCrModPFermat(long long n, long long r) {
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (i * fac[i - 1]) % mod;
    return (fac[n] * modInverse(fac[r]) % mod
            * modInverse(fac[n - r]) % mod)
        % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> colors(n);
    for (auto& color : colors) {
        cin >> color;
    }

    map<int, int> colorCounts;
    for (const auto& color : colors) {
        colorCounts[color]++;
    }

    long long answer = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        long long temp = 1;
        int total = 0;
        for (int i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                temp = (temp * colorCounts[i + 1]) % mod;
                total++;
            }
        }
        if (total % 2 == k % 2) {
            answer = (answer + temp) % mod;
        } else {
            answer = (answer - temp + mod) % mod;
        }
    }

    cout << nCrModPFermat(answer, k) << endl;

    return 0;
}