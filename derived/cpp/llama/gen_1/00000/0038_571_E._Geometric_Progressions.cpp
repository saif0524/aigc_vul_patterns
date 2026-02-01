#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

const int MOD = 1e9 + 7;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<int> factors(n);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        long long x = b[i];
        for (int j = 2; j * j <= x; ++j) {
            while (x % j == 0) {
                x /= j;
                ++cnt;
            }
        }
        if (x > 1) ++cnt;
        factors[i] = cnt;
    }

    vector<long long> vals;
    for (int i = 0; i < n; ++i) {
        long long x = b[i];
        for (int j = 2; j * j <= x; ++j) {
            while (x % j == 0) {
                x /= j;
            }
        }
        if (x > 1) vals.push_back(x);
        else vals.push_back(b[i]);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    long long res = -1;
    for (int i = 0; i < n; ++i) {
        long long curr = a[i];
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (a[j] % curr != 0 || b[j] % vals[0] != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            res = curr;
            break;
        }
    }

    if (res == -1) {
        cout << -1 << '\n';
        return 0;
    }

    long long lcm_val = 1;
    for (int i = 0; i < n; ++i) {
        lcm_val = lcm(lcm_val, b[i]);
    }

    long long ans = res;
    while (true) {
        for (int i = 0; i < n; ++i) {
            if (a[i] % ans != 0) {
                ans *= lcm_val;
                break;
            }
        }
        if (ans > 1e18) break;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] % ans != 0) {
                ok = false;
                break;
            }
        }
        if (ok) break;
        ans *= lcm_val;
    }

    cout << ans % MOD << '\n';

    return 0;
}