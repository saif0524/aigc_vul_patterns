#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    vector<int> b(N);
    for (int i = 1; i < N; i++) {
        cin >> b[i];
        b[i]--;
    }

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    dp[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k < i; k++) {
                if (k!= b[i - 1] && k + 1!= b[i - 1]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
            if (i - j!= b[i - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][i - 1]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = (ans + dp[N][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}