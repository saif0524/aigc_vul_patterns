#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> souvenirs(n);
    for (int i = 0; i < n; ++i) {
        cin >> souvenirs[i].first >> souvenirs[i].second;
    }

    vector<int> dp(m + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int w = m; w >= souvenirs[i].first; --w) {
            dp[w] = max(dp[w], dp[w - souvenirs[i].first] + souvenirs[i].second);
        }
    }

    cout << dp[m] << endl;

    return 0;
}