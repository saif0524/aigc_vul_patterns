#include <bits/stdc++.h>

using namespace std;

int getWeight(char c) {
    return c - 'a' + 1;
}

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    vector<bool> used(n, false);
    int ans = -1;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 1; j--) {
            if (dp[i][j - 1] != -1) {
                int prevWeight = (i > 0 && used[i - 1]) ? getWeight(s[i - 1]) : 0;
                if (getWeight(s[i]) - prevWeight >= 2) {
                    int newWeight = dp[i][j - 1] + getWeight(s[i]);
                    if (dp[i + 1][j] == -1 || newWeight < dp[i + 1][j]) {
                        dp[i + 1][j] = newWeight;
                        used[i] = true;
                    }
                }
            }
        }
        if (dp[i + 1][k] != -1 && (ans == -1 || dp[i + 1][k] < ans)) {
            ans = dp[i + 1][k];
        }
    }

    cout << ans << endl;

    return 0;
}