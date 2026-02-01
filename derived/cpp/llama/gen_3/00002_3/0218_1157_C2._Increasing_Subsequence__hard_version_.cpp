#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            dp[i][j] = 1;
            if (a[i] < a[j]) {
                dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1);
            }
            if (a[j] < a[i]) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
            }
            for (int k = i + 1; k < j; k++) {
                if (a[k] > a[i] && a[k] > a[j]) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + 1);
                }
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    string ans = "";
    int i = 0, j = n - 1;
    while (i <= j) {
        if (i == j) {
            ans += 'L';
            break;
        }
        if (a[i] < a[j]) {
            if (dp[i][j] == dp[i + 1][j] + 1) {
                ans += 'L';
                i++;
            } else {
                for (int k = i + 1; k < j; k++) {
                    if (a[k] > a[i] && a[k] > a[j] && dp[i][j] == dp[i][k - 1] + dp[k + 1][j] + 1) {
                        ans += 'L';
                        i++;
                        break;
                    }
                }
            }
        } else if (a[j] < a[i]) {
            if (dp[i][j] == dp[i][j - 1] + 1) {
                ans += 'R';
                j--;
            } else {
                for (int k = i + 1; k < j; k++) {
                    if (a[k] > a[i] && a[k] > a[j] && dp[i][j] == dp[i][k - 1] + dp[k + 1][j] + 1) {
                        ans += 'R';
                        j--;
                        break;
                    }
                }
            }
        } else {
            ans += 'L';
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}