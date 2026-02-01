#include <iostream>
#include <vector>

using namespace std;
const int mod = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(s + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    int ans = 0;
    for (int r = 1; r <= n; r++) {
        for (int l = r; l > 0; l--) {
            for (int k = 1; k <= s; k++) {
                if (k < a[l - 1]) dp[l - 1][k] = dp[l][k];
                else dp[l - 1][k] = add(dp[l][k], dp[l - 1][k - a[l - 1]]);
            }
            ans = add(ans, dp[l - 1][s]);
        }
    }

    cout << ans << endl;
    return 0;
}