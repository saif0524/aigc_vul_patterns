#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i + 1 <= j && j <= a[i]) {
                dp[i][j] = 1;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] && dp[k][j] && i != k && k != j && !dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dp[i][j] > 0) {
                sum += dp[i][j];
            }
        }
    }

    cout << sum << endl;
    return 0;
}