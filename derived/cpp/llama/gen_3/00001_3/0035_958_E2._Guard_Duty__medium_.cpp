#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    vector<int> dp(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        int min_val = 1e9;
        for (int j = i; j < n; j++) {
            min_val = min(min_val, dp[i - 1] + t[j] - t[j - i]);
        }
        dp[i] = min_val;
    }

    cout << dp[k] << endl;

    return 0;
}