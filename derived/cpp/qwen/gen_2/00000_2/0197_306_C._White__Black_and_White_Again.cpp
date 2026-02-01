#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000009;

int add(int a, int b) {
    return (0LL + a + b) % MOD;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int main() {
    int n, w, b;
    cin >> n >> w >> b;

    if (n != w + b || n < 3) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> fact(w + b + 1, 1);
    for (int i = 2; i <= w + b; ++i) {
        fact[i] = mul(fact[i - 1], i);
    }

    int inv_fact[w + b + 1] = {0};
    inv_fact[w + b] = 1;
    for (int i = w + b - 1; i >= 1; --i) {
        inv_fact[i] = mul(inv_fact[i + 1], i + 1);
    }

    auto nCr = [&](int n, int r) {
        if (r > n) return 0;
        return mul(fact[n], mul(inv_fact[r], inv_fact[n - r]));
    };

    int ans = 0;
    for (int i = 1; i <= w - 1; ++i) { // White stripe 1 length
        for (int j = 1; j <= b; ++j) { // Black stripe length
            if (i + j < n - 1) {
                int remaining_white = w - i;
                int remaining_days = n - i - j - 1;
                if (remaining_white >= remaining_days) {
                    ans = add(ans, mul(nCr(w, i), mul(nCr(b, j), nCr(remaining_white, remaining_days))));
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}