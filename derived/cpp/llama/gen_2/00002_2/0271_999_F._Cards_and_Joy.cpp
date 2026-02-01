#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> c(k * n);
    for (int i = 0; i < k * n; i++) {
        cin >> c[i];
    }

    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    vector<int> h(k);
    for (int i = 0; i < k; i++) {
        cin >> h[i];
    }

    vector<vector<int>> count(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k * n; j++) {
            if (c[j] == f[i]) {
                count[i][0]++;
            }
        }
        for (int j = 1; j <= k; j++) {
            count[i][j] = min(count[i][j - 1], k - j + 1);
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(k * n + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = k * n; j >= 0; j--) {
            if (dp[i][j] == -1) continue;
            for (int l = 0; l <= k && l <= count[i][0] && j + l <= k * n; l++) {
                dp[i + 1][j + l] = max(dp[i + 1][j + l], dp[i][j] + h[l]);
            }
        }
    }

    cout << dp[n][k * n] << endl;

    return 0;
}