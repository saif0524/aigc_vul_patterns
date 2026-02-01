#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return (a - b + MOD) % MOD;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int ans = 0;

    for (int l = 0; l < N; ++l) {
        for (int r = l; r < N; ++r) {
            vector<int> dp(S + 1);
            dp[0] = 1;
            for (int i = l; i <= r; ++i) {
                vector<int> ndp(S + 1);
                for (int j = 0; j <= S; ++j) {
                    ndp[j] = add(ndp[j], dp[j]);
                    if (j + A[i] <= S) {
                        ndp[j + A[i]] = add(ndp[j + A[i]], dp[j]);
                    }
                }
                dp = ndp;
            }
            ans = add(ans, dp[S]);
        }
    }

    cout << ans << '\n';

    return 0;
}