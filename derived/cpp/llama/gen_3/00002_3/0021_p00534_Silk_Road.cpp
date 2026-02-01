#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    vector<int> C(M);
    for (int i = 0; i < M; i++) {
        cin >> C[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dp[i][j]!= INT_MAX) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
                if (j + 1 <= M - (N - i - 1)) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + D[i] * C[j]);
                }
            }
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}