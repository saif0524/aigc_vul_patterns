#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 5005;
const double EPS = 1e-9;

int n, T;
int p[MAX_N], t[MAX_N];
double dp[MAX_N][MAX_N];

int main() {
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> t[i];
    }

    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        double sum = 0.0;
        for (int j = 0; j <= T; j++) {
            sum += dp[i - 1][j];
            dp[i][j] = 0.0;
        }
        for (int j = 0; j < T; j++) {
            dp[i][j + 1] += sum * (1.0 - p[i] / 100.0);
            if (j + 1 >= t[i]) {
                dp[i][j + 1] += sum * (1.0 - (1.0 - p[i] / 100.0) * (1.0 - (1.0 - (1.0 - p[i] / 100.0) * (t[i] - 1))));
            } else {
                dp[i][j + 1] += sum * (1.0 - (1.0 - p[i] / 100.0) * (t[i] - j - 1));
            }
        }
    }

    double ans = 0.0;
    for (int i = 1; i <= n; i++) {
        double sum = 0.0;
        for (int j = 0; j <= T; j++) {
            sum += dp[i][j];
        }
        ans += sum;
    }

    printf("%.9f\n", ans);

    return 0;
}