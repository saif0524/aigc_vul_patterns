#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, A;
    cin >> N >> A;

    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(N * 50 + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = N; j >= 1; j--) {
            for (int k = N * 50; k >= x[i]; k--) {
                dp[j][k] += dp[j - 1][k - x[i]];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i * A <= N * 50) {
            ans += dp[i][i * A];
        }
    }

    cout << ans << endl;

    return 0;
}