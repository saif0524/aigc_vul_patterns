#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MOD = 1009;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for (auto& p : cnt) {
        int c = p.second;
        for (int i = m; i >= 0; i--) {
            for (int j = k; j >= 0; j--) {
                for (int x = 1; x <= min(c, j); x++) {
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - x]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = (ans + dp[i][k]) % MOD;
    }

    cout << ans << endl;

    return 0;
}