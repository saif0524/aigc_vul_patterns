#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int solve(int N, vector<int> &a) {
    int dp[N + 1] = {};
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (find(a.begin(), a.end(), i) != a.end()) continue;
        if (i - 1 >= 0 && find(a.begin(), a.end(), i - 1) == a.end()) {
            dp[i] += dp[i - 1];
            dp[i] %= MOD;
        }
        if (i - 2 >= 0 && find(a.begin(), a.end(), i - 2) == a.end()) {
            dp[i] += dp[i - 2];
            dp[i] %= MOD;
        }
    }
    return dp[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i];
    }

    cout << solve(N, a) << "\n";

    return 0;
}