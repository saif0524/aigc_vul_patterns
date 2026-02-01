#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    vector<vector<int>> prev(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    for (int length = 1; length < n; length++) {
        for (int i = 0; i < n - length; i++) {
            int j = i + length;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + abs(points[i].first - points[k].first) + abs(points[i].second - points[k].second);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    prev[i][j] = k;
                }
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}