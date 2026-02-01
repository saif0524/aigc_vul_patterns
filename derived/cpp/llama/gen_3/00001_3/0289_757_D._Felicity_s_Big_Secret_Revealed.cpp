#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> f(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int x = 0;
            for (int k = j - 1; k < i; k++) {
                x = 2 * x + (s[k] - '0');
            }
            dp[i][j] = x;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[i][j] > 0) {
                f[i]++;
            }
        }
    }

    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        g[i][1] = f[i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
            for (int k = 1; k < i; k++) {
                if (f[k] > 0 && g[i - k][j - 1] > 0) {
                    g[i][j] = (g[i][j] + g[i - k][j - 1]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = (ans + g[i][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}