#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;

int n;
int x[MAXN], h[MAXN];
int dp[MAXN][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> h[i];
    }

    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0];

        for (int j = 1; j < i; j++) {
            if (x[i] - h[i] > x[j] && x[j] + h[j] < x[i]) {
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
            }
            if (x[i] + h[i] < x[j] && x[j] - h[j] > x[i]) {
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
            }
        }
    }

    cout << max(dp[n][0], dp[n][1]);
    return 0;
}