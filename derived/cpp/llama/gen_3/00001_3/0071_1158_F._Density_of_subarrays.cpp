#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) {
    return (long long)a * b % MOD;
}

int powmod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return powmod(a, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<vector<int>> dp(n + 1, vector<int>(c, 0));
    for (int i = 0; i < n; i++) {
        dp[i + 1][a[i]] = 1;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < c; j++) {
            dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
        }
    }

    vector<int> ans(n + 1, 0);
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                b.push_back(a[i]);
            }
        }

        int p = 0;
        for (int i = 0; i < c; i++) {
            bool ok = true;
            for (int j = 0; j <= b.size(); j++) {
                int l = 0, r = b.size();
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (b[mid] <= i) l = mid + 1;
                    else r = mid;
                }
                if (l == j) ok = false;
            }
            if (ok) p++;
        }

        ans[p] = add(ans[p], 1);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            ans[i] = add(ans[i], mul(ans[j], dp[i][j]));
        }
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}