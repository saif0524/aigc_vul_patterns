#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, q;
vector<long long> a, w;
vector<long long> prefixw, prefixwa;
vector<long long> suffixw, suffixwa;

void build() {
    prefixw[0] = w[0];
    prefixwa[0] = 1LL * w[0] * a[0];
    for (int i = 1; i < n; ++i) {
        prefixw[i] = (prefixw[i - 1] + w[i]) % MOD;
        prefixwa[i] = (prefixwa[i - 1] + 1LL * w[i] * a[i]) % MOD;
    }

    suffixw[n - 1] = w[n - 1];
    suffixwa[n - 1] = 1LL * w[n - 1] * a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffixw[i] = (suffixw[i + 1] + w[i]) % MOD;
        suffixwa[i] = (suffixwa[i + 1] + 1LL * w[i] * a[i]) % MOD;
    }
}

long long mod_inverse(long long x) {
    long long res = 1;
    for (long long y = MOD - 2; y > 0; y >>= 1) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

long long mod_sub(long long a, long long b) {
    return (a - b + MOD) % MOD;
}

long long query(int l, int r) {
    if (l == r) return 0;

    long long total_w = (prefixw[r] - (l > 0 ? prefixw[l - 1] : 0) + MOD) % MOD;
    long long left_wa = (l > 0 ? prefixwa[l - 1] : 0);
    long long right_wa = (suffixwa[r] - (r < n - 1 ? suffixwa[r + 1] : 0) + MOD) % MOD;
    long long middle_wa = mod_sub(prefixwa[r], left_wa);
    long long left_g = mod_sub(middle_wa, 1LL * (r - l + 1) * mod_inverse(total_w) % MOD * suffixw[r] % MOD);
    long long right_g = mod_sub(mod_sub(middle_wa, 1LL * (r - l + 1) * mod_inverse(total_w) % MOD * left_wa), 1LL * (r - l + 1) * a[l]);
    long long left_cost = (left_g * (total_w - left_w[l - 1] + MOD) % MOD * mod_inverse(total_w) % MOD + left_w[l - 1] * left_g % MOD) % MOD;
    long long right_cost = (1LL * right_w[r] * (r - l + 1) % MOD - right_g * (total_w - right_w[r + 1] + MOD) % MOD * mod_inverse(total_w) % MOD) % MOD;
    return (left_cost + right_cost) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    a.resize(n);
    w.resize(n);
    prefixw.resize(n);
    prefixwa.resize(n);
    suffixw.resize(n);
    suffixwa.resize(n);
    for (auto &x : a) cin >> x;
    for (auto &x : w) cin >> x;

    build();

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x < 0) {
            int id = -x - 1;
            prefixwa[id] = prefixwa[id] - 1LL * w[id] * a[id] % MOD + 1LL * y * a[id] % MOD;
            suffixwa[id] = suffixwa[id] - 1LL * w[id] * a[id] % MOD + 1LL * y * a[id] % MOD;
            prefixw[id] = prefixw[id] - w[id] + MOD + y;
            suffixw[id] = suffixw[id] - w[id] + MOD + y;
            w[id] = y;
            for (int j = id + 1; j < n; ++j) {
                prefixw[j] = (prefixw[j] - prefixw[j - 1] + MOD + prefixw[j - 1] - w[j - 1] + MOD + y) % MOD;
                prefixwa[j] = (prefixwa[j] - prefixwa[j - 1] + MOD + prefixwa[j - 1] - 1LL * w[j - 1] * a[j - 1] % MOD + 1LL * y * a[j - 1] % MOD) % MOD;
            }
            for (int j = id - 1; j >= 0; --j) {
                suffixw[j] = (suffixw[j] - suffixw[j + 1] + MOD + suffixw[j + 1] - w[j + 1] + MOD + y) % MOD;
                suffixwa[j] = (suffixwa[j] - suffixwa[j + 1] + MOD + suffixwa[j + 1] - 1LL * w[j + 1] * a[j + 1] % MOD + 1LL * y * a[j + 1] % MOD) % MOD;
            }
        } else {
            int l = x - 1, r = y - 1;
            cout << query(l, r) << "\n";
        }
    }

    return 0;
}