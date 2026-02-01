#include <bits/stdc++.h>
#define INF 1e18
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> items(n);
    for (auto& item : items) {
        cin >> item.first >> item.second;
    }
    vector<long long> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            dp[j + 1] = min(dp[j + 1], dp[j] + items[i - 1].second);
            if (items[i - 1].first > 0 && j > 0) {
                dp[j] = min(dp[j], dp[j - 1] + items[i - 1].second);
            }
        }
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
    return 0;
}