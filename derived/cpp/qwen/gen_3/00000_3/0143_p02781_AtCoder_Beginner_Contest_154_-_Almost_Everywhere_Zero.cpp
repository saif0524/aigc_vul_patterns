#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countNumbersWithKDigits(const string& N, int K) {
    int n = N.size();
    if (K == 0) return 0;
    if (K > n) return 0;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(K + 1, vector<int>(2, 0)));
    dp[0][0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= K; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int d = 0; d <= 9; ++d) {
                    int newK = j + (d > 0);
                    int newKConstraint = k || (d < N[i - 1] - '0');
                    if (newK <= K) {
                        dp[i][newK][newKConstraint] += dp[i - 1][j][k];
                    }
                }
            }
        }
    }

    int result = dp[n][K][0] + dp[n][K][1];
    if (K == 1) {
        result -= 1; // Exclude the number 0
    }
    return result;
}

int main() {
    string N;
    int K;
    cin >> N >> K;
    cout << countNumbersWithKDigits(N, K) << endl;
    return 0;
}