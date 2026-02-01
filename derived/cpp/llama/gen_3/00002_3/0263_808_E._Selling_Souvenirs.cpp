#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> souvenirs;
    for (int i = 0; i < n; i++) {
        int wi, ci;
        cin >> wi >> ci;
        souvenirs.emplace_back(wi, ci);
    }

    vector<long long> dp(m + 1, 0);
    for (const auto& souvenir : souvenirs) {
        for (int w = m; w >= souvenir.first; w--) {
            dp[w] = max(dp[w], dp[w - souvenir.first] + souvenir.second);
        }
    }

    cout << dp[m] << endl;

    return 0;
}