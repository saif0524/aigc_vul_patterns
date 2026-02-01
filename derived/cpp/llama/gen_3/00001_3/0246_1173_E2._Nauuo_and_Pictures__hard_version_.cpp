#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int mul(int a, int b) {
    return (long long)a * b % MOD;
}

int pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return pow(a, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), w(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> w[i];

    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        int sum = accumulate(w.begin(), w.end(), 0);
        int p = mul(w[i], inv(sum));
        int q = add(mul(p, add(w[i], 1)), mul(sub(1, p), sub(w[i], 1)));
        res[i] = mul(q, inv(add(sum, m)));
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";

    return 0;
}