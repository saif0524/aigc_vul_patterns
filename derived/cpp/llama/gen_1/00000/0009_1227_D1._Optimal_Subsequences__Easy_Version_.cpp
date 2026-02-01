#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100 + 5;

int n, m;
int a[MAX_N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k, pos;
        cin >> k >> pos;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MIN));
        vector<vector<bool>> take(n + 1, vector<bool>(k + 1, false));
        dp[0][0] = 0;
        for (int j = 1; j <= n; j++) {
            for (int l = 0; l <= k; l++) {
                if (dp[j - 1][l] > dp[j][l]) {
                    dp[j][l] = dp[j - 1][l];
                    take[j][l] = take[j - 1][l];
                }
                if (l < k && dp[j - 1][l] + a[j - 1] > dp[j][l + 1]) {
                    dp[j][l + 1] = dp[j - 1][l] + a[j - 1];
                    take[j][l + 1] = true;
                } else if (l < k && dp[j - 1][l] + a[j - 1] == dp[j][l + 1] && (take[j][l + 1] == false || a[j - 1] < a[j - 1 - l])) {
                    take[j][l + 1] = true;
                }
            }
        }
        vector<int> ans;
        int idx = n, cnt = k;
        while (cnt > 0) {
            if (take[idx][cnt]) {
                ans.push_back(a[idx - 1]);
            }
            idx--;
            cnt -= take[idx + 1][cnt];
        }
        reverse(ans.begin(), ans.end());
        cout << ans[pos - 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}