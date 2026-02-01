#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> souvenirs(n);
    for (int i = 0; i < n; i++) {
        cin >> souvenirs[i].first >> souvenirs[i].second;
    }

    vector<ll> dp(m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= souvenirs[i].first; j--) {
            dp[j] = max(dp[j], dp[j - souvenirs[i].first] + souvenirs[i].second);
        }
    }

    cout << dp[m] << endl;

    return 0;
}