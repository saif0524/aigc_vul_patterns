#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) {
                int cost = 0;
                bool ok = true;
                for (int k = 0; k < m; k++) {
                    int cnt = 0;
                    for (int l = 0; l < n; l++) {
                        if (l == j) continue;
                        if ((i & (1 << l)) == 0 && s[l][k] == s[j][k]) cnt++;
                    }
                    if (cnt == 0) {
                        ok = false;
                        break;
                    }
                    cost += a[j][k];
                }
                if (ok) {
                    dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + cost);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}