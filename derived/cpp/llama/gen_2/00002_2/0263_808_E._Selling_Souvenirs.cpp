#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> c[i];
    }

    vector<long long> dp(m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }

    cout << dp[m] << endl;

    return 0;
}