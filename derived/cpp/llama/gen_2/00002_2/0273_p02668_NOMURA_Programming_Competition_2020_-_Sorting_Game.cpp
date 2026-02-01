#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> dp(M + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; ++i) {
        vector<int> ndp(M + 1, 0);
        for (int j = 0; j <= M; ++j) {
            ndp[j] = add(ndp[j], mul(dp[j], binpow(2, M - j)));
            if (j > 0) ndp[j] = add(ndp[j], mul(dp[j - 1], binpow(2, M - j)));
        }
        swap(dp, ndp);
    }

    cout << dp[M] << '\n';

    return 0;
}