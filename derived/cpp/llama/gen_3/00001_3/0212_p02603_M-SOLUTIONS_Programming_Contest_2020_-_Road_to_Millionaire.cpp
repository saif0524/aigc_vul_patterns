#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(N * 100 + 1, -1));
    dp[0][0] = 1000;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N * 100; j++) {
            if (dp[i][j] == -1) continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            if (j >= A[i]) {
                dp[i + 1][j - A[i] + A[i]] = max(dp[i + 1][j - A[i] + A[i]], dp[i][j]);
                dp[i + 1][j + A[i]] = max(dp[i + 1][j + A[i]], dp[i][j]);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= N * 100; i++) {
        ans = max(ans, dp[N][i]);
    }

    cout << ans << endl;

    return 0;
}