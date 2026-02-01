#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    
    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].first >> items[i].second;
    }
    
    vector<long long> dp(W + 1, 0);
    
    for (const auto& item : items) {
        for (int w = W; w >= item.second; --w) {
            dp[w] = max(dp[w], dp[w - item.second] + item.first);
        }
    }
    
    cout << dp[W] << endl;
    
    return 0;
}