#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<bool> broken(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        broken[x] = true;
    }

    vector<long long> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
        if (broken[i]) continue;
        if (i - 1 >= 0) dp[i] += dp[i - 1];
        if (i - 2 >= 0) dp[i] += dp[i - 2];
        dp[i] %= MOD;
    }

    cout << dp[N] << endl;

    return 0;
}