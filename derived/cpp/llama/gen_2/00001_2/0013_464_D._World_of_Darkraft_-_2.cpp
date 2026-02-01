#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    const int MAX_N = 1005;
    double dp[MAX_N][MAX_N] = {};

    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0.0;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i][j - 1] * (i - 1) + (dp[i - 1][j - 1] + (j + 1) / 2.0)) / (double)i;
        }
    }

    cout << fixed << setprecision(10) << dp[k][n] << endl;

    return 0;
}