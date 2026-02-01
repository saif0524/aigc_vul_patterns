#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> occupied, empty;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            occupied.push_back(i);
        } else {
            empty.push_back(i);
        }
    }

    int m = occupied.size();
    int k = empty.size();

    vector<vector<int>> dp(m + 1, vector<int>(k + 1, INT_MAX));

    for (int j = 0; j <= k; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= k; j++) {
            for (int p = j - 1; p >= i - 1; p--) {
                dp[i][j] = min(dp[i][j], dp[i - 1][p] + abs(occupied[i - 1] - empty[j - 1]));
            }
        }
    }

    cout << dp[m][k] << endl;

    return 0;
}