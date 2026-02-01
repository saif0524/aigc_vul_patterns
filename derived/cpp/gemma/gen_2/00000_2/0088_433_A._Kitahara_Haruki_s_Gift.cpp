#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    long long total_weight = accumulate(weights.begin(), weights.end(), 0LL);

    if (total_weight % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    long long target_weight = total_weight / 2;

    vector<bool> dp(target_weight + 1, false);
    dp[0] = true;

    for (int weight : weights) {
        for (int i = target_weight; i >= weight; --i) {
            dp[i] = dp[i] || dp[i - weight];
        }
    }

    if (dp[target_weight]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}