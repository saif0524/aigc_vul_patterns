#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        vector<int> C(m);
        for (int i = 0; i < m; i++) cin >> C[i];

        vector<int> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];

        vector<vector<int>> dp(n + 1, vector<int>(256, INT_MAX));
        dp[0][128] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 256; j++) {
                if (dp[i][j] == INT_MAX) continue;

                for (int k = 0; k < m; k++) {
                    int nj = j + C[k];
                    nj = max(0, min(255, nj));

                    dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + (x[i] - j) * (x[i] - j));
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < 256; i++) {
            ans = min(ans, dp[n][i]);
        }

        cout << ans << endl;
    }

    return 0;
}