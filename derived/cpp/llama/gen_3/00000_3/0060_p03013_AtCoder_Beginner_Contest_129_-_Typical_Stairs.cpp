#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> broken_steps(M);
    for (int i = 0; i < M; i++) {
        cin >> broken_steps[i];
    }

    vector<bool> is_broken(N + 1, false);
    for (int step : broken_steps) {
        is_broken[step] = true;
    }

    vector<long long> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (is_broken[i]) {
            continue;
        }

        if (i - 1 >= 0) {
            dp[i] += dp[i - 1];
        }

        if (i - 2 >= 0) {
            dp[i] += dp[i - 2];
        }

        dp[i] %= MOD;
    }

    cout << dp[N] << endl;

    return 0;
}