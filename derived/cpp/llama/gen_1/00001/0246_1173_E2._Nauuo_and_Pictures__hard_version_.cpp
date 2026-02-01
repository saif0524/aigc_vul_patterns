#include <iostream>
#include <vector>

using namespace std;

const int mod = 998244353;

int add(int x, int y) {
    x += y;
    if (x >= mod) x -= mod;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0) x += mod;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % mod;
}

int pow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
        y >>= 1;
    }
    return res;
}

int inv(int x) {
    return pow(x, mod - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<int> sum_w(m + 1);
    vector<int> sum_aw(m + 1);

    for (int i = 0; i < n; i++) {
        sum_w[0] = add(sum_w[0], w[i]);
        sum_aw[0] = add(sum_aw[0], mul(a[i], w[i]));
    }

    for (int i = 1; i <= m; i++) {
        sum_w[i] = add(sum_w[i - 1], sum_aw[i - 1]);
        sum_aw[i] = add(mul(sum_aw[i - 1], sum_w[i - 1]), mul(sub(sum_w[i - 1], sum_aw[i - 1]), sum_w[i - 1]));
        sum_aw[i] = mul(sum_aw[i], inv(mul(sum_w[i - 1], sum_w[i - 1])));
    }

    for (int i = 0; i < n; i++) {
        int x = mul(w[i], sum_aw[m]);
        int y = mul(sum_w[m], w[i]);
        if (a[i] == 0) y = sub(y, sum_w[m]);
        else y = add(y, sum_w[m]);
        cout << mul(add(x, y), inv(mul(sum_w[m], sum_w[m]))) << "\n";
    }

    return 0;
}