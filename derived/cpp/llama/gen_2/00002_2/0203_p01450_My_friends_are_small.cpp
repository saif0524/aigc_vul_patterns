#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weights[i - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - weights[i - 1]]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= W; i++) {
        ans = (ans + dp[N][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}