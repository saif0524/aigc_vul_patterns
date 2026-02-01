#include <iostream>
#include <cstdio>

using namespace std;

const int mod = 998244353;

inline int add(int x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % mod;
}

inline int qpow(int x, int y) {
    int ans = 1;
    for (; y; y >>= 1, x = mul(x, x)) {
        if (y & 1) {
            ans = mul(ans, x);
        }
    }
    return ans;
}

inline int inv(int x) {
    return qpow(x, mod - 2);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int dp[300001] = {0};
    int pre[300001] = {0};
    for (int i = 1; i <= sum; ++i) {
        dp[i] = i;
        for (int j = 1; j < i; ++j) {
            dp[i] = add(dp[i], mul(j, sub(pre[i - j], pre[j - 1])));
        }
        pre[i] = add(pre[i - 1], dp[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = add(ans, mul(dp[sum - a[i]], mul(a[i], inv(sum))));
    }
    cout << mul(ans, inv(n - 1)) << '\n';
    return 0;
}