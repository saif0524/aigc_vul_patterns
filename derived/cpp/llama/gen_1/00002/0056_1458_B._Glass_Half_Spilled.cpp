#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 105;
const double EPS = 1e-9;

int n;
int a[MAXN], b[MAXN];
double dp[MAXN][MAXN * MAXN];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n * 100; j++) {
            dp[i][j] = -1e9;
        }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            for (int k = n * 100; k >= a[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - 1][k - a[i]] + b[i]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        double ans = 0;
        for (int j = 0; j <= n * 100; j++) {
            ans = max(ans, min((double)j, dp[i][j] + j * 0.5));
        }
        printf("%.9f ", ans);
    }

    cout << endl;
}

int main() {
    solve();
    return 0;
}