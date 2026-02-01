#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> m;
    while (m--) {
        int k, pos;
        cin >> k >> pos;
        --pos;

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        vector<vector<pair<int, int>>> prev(k + 1, vector<pair<int, int>>(n + 1, {-1, -1}));

        dp[0][0] = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] != -1) {
                    for (int idx = j; idx < n; ++idx) {
                        if (dp[i + 1][idx + 1] == -1 || 
                            dp[i][j] + a[idx] > dp[i + 1][idx + 1] || 
                            (dp[i][j] + a[idx] == dp[i + 1][idx + 1] && 
                             a[idx] < a[prev[i + 1][idx + 1].first])) {
                            dp[i + 1][idx + 1] = dp[i][j] + a[idx];
                            prev[i + 1][idx + 1] = {idx, a[idx]};
                        }
                    }
                }
            }
        }

        vector<int> res;
        int curr = k, idx = n;
        while (curr) {
            while (dp[curr][idx] == -1) --idx;
            res.push_back(prev[curr][idx].second);
            idx = prev[curr][idx].first;
            --curr;
        }

        reverse(res.begin(), res.end());
        cout << res[pos - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}