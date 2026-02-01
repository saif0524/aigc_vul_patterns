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

    vector<vector<long long>> dp(N + 1, vector<long long>(1000 + 1, -1));
    dp[0][1000] = 1000;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (dp[i][j] == -1) continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            if (j >= A[i]) {
                dp[i + 1][j - A[i] + A[i]] = max(dp[i + 1][j - A[i] + A[i]], dp[i][j]);
                if (i < N - 1) {
                    dp[i + 2][j - A[i] + A[i + 1]] = max(dp[i + 2][j - A[i] + A[i + 1]], dp[i][j]);
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 1000; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}