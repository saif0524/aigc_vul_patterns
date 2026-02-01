#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;

    vector<int> t(N);
    for (auto &x : t) cin >> x;

    sort(t.begin(), t.end());

    vector<vector<int>> dp(K + 1, vector<int>(N, INF));
    for (int i = 0; i < N; ++i) dp[0][i] = 0;

    for (int k = 1; k <= K; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[k][i] = min(dp[k][i], dp[k - 1][j] + t[i] - t[j]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < N; ++i) {
        ans = min(ans, dp[K][i]);
    }

    cout << ans << '\n';

    return 0;
}