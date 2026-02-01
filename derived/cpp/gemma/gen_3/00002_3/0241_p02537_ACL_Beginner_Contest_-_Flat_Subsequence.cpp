#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(a[i] - a[j]) <= k) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_len = 0;
    for (int i = 0; i < n; ++i) {
        max_len = max(max_len, dp[i]);
    }

    cout << max_len << endl;

    return 0;
}