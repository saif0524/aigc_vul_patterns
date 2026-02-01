#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> trees(n);
    for (int i = 0; i < n; ++i) {
        cin >> trees[i].first >> trees[i].second;
    }

    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        int maxVal = 0;
        for (int j = 0; j < i; ++j) {
            if (trees[i].first >= trees[j].first + trees[j].second || 
                trees[i].first + trees[i].second <= trees[j].first) {
                maxVal = max(maxVal, dp[j]);
            }
        }
        dp[i] = max(maxVal + 1, dp[i-1]);
    }

    cout << dp[n-1] << endl;

    return 0;
}