#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, pair<int, int>>> books(n);
    for (int i = 0; i < n; ++i) {
        cin >> books[i].first >> books[i].second.first >> books[i].second.second;
    }
    sort(books.begin(), books.end());

    long long dp[2][k+1][k+1];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= k; ++l) {
                dp[i%2][j][l] = dp[(i-1)%2][j][l];
                int a = books[i-1].second.first;
                int b = books[i-1].second.second;
                int t = books[i-1].first;
                if (j-a >= 0 && l-b >= 0 && dp[(i-1)%2][j-a][l-b] != -1) {
                    dp[i%2][j][l] = max(dp[i%2][j][l], dp[(i-1)%2][j-a][l-b] + t);
                }
            }
        }
    }

    long long ans = -1;
    if (dp[n%2][k][k] != -1) {
        ans = dp[n%2][k][k];
    }
    cout << (ans == -1 ? -1 : 0LL + n * 1e4 - ans) << '\n';
}