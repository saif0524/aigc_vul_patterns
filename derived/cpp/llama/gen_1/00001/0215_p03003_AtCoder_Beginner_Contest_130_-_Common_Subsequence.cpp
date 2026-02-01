#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> S(N), T(M);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < M; i++) cin >> T[i];

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 0; i <= N; i++) dp[i][0] = 1;
    for (int i = 0; i <= M; i++) dp[0][i] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mod) % mod;
            if (S[i - 1] == T[j - 1]) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}