#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) {
    return (a + b) % mod;
}

int sub(int a, int b) {
    return (a - b + mod) % mod;
}

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int powmod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return powmod(a, mod - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> c(n);
    for (int& x : c) {
        cin >> x;
    }

    vector<int> b(n - 1);
    for (int& x : b) {
        cin >> x;
    }

    int q;
    cin >> q;

    vector<int> x(q);
    for (int& y : x) {
        cin >> y;
    }

    for (int i = 0; i < q; ++i) {
        int ans = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            int sum = 0;
            int good = 1;
            for (int j = 0; j < n; ++j) {
                int bit = (mask >> j) & 1;
                if (bit) {
                    sum += c[j];
                } else {
                    sum -= c[j];
                }
                if (bit && c[j] == 0) {
                    good = 0;
                }
                if (!bit && c[j] == 0) {
                    good = 0;
                }
            }
            double value = -x[i];
            for (int j = 0; j < n - 1; ++j) {
                value += b[j];
            }
            if ((sum >= value * 2 && good) || (sum > value * 2 && good)) {
                ans = add(ans, 1);
            }
        }

        vector<int> choices(n);
        for (int j = 0; j < n; ++j) {
            choices[j] = c[j] + 1;
        }

        int perm = 1;
        for (int j = 0; j < n; ++j) {
            perm = mul(perm, choices[j]);
        }

        ans = sub(perm, ans);

        cout << ans << '\n';
    }

    return 0;
}