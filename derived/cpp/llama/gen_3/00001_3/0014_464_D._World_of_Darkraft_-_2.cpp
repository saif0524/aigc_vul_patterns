#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 100005;
const int MAX_K = 105;

double dp[MAX_N][MAX_K];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i == 0) {
                dp[i][j] = 0;
            } else {
                double sum = 0;
                for (int l = 1; l <= j; l++) {
                    sum += (l + 1) / 2.0;
                }
                dp[i][j] = (1.0 / k) * (sum + dp[i - 1][j]);
            }
        }
    }

    cout << fixed << setprecision(10) << dp[n][k] << endl;

    return 0;
}