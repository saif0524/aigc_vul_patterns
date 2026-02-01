#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> dp(n * 2 + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < m; i++) {
        vector<int> ndp(n * 2 + 1, INT_MAX);
        for (int j = 0; j <= n * 2; j++) {
            if (dp[j]!= INT_MAX) {
                if (j > 0) {
                    ndp[j - 1] = min(ndp[j - 1], dp[j] + a[i % n]);
                }
                if (j < n * 2) {
                    ndp[j + 1] = min(ndp[j + 1], dp[j] + b[i % n]);
                }
            }
        }
        dp = ndp;
    }

    cout << dp[0] << endl;

    return 0;
}