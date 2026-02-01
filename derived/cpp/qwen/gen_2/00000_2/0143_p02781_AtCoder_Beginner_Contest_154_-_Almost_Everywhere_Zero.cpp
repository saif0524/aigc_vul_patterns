#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countNumbersWithKNonZeroDigits(const string& N, int K) {
    int n = N.size();
    vector<vector<int>> dp(n + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= K; ++j) {
            for (int d = 0; d <= 9; ++d) {
                int nz = j + (d > 0);
                if (nz <= K) {
                    dp[i][nz] += dp[i - 1][j];
                }
            }
        }
        for (int nz = 0; nz <= K; ++nz) {
            for (int d = 1; d < N[n - i] - '0'; ++d) {
                dp[i][nz + 1] += dp[i - 1][nz];
            }
            break;
        }
    }

    return dp[n][K] - dp[n][K - 1];
}

int main() {
    string N;
    int K;
    cin >> N >> K;
    cout << countNumbersWithKNonZeroDigits(N, K) << endl;
    return 0;
}