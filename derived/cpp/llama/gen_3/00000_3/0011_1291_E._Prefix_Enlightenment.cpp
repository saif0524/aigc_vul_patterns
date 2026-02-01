#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cstdint>

using namespace std;

const int64_t INF = INT64_MAX / 2;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<vector<int>> a(k);
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        a[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < k; i++) {
        for (int j : a[i]) {
            g[j].push_back(i);
        }
    }

    vector<int64_t> m(n);
    for (int i = 0; i < n; i++) {
        m[i] = INF;
    }

    for (int i = 0; i < n; i++) {
        vector<int64_t> dp(1 << k, INF);
        dp[0] = 0;

        for (int j = 0; j <= i; j++) {
            vector<int> ng;
            for (int x : g[j]) {
                ng.push_back(x);
            }

            if (s[j] == '0') {
                for (int mask = 0; mask < (1 << k); mask++) {
                    int64_t val = dp[mask];

                    for (int x : ng) {
                        if (mask & (1 << x)) continue;
                        val = min(val, dp[mask | (1 << x)] + 1);
                    }
                }
            } else {
                for (int mask = 0; mask < (1 << k); mask++) {
                    int64_t val = dp[mask];

                    for (int x : ng) {
                        if (!(mask & (1 << x))) continue;
                        val = min(val, dp[mask ^ (1 << x)] + 1);
                    }
                }
            }

            for (int mask = 0; mask < (1 << k); mask++) {
                dp[mask] = min(dp[mask], dp[(((1 << k) - 1) ^ mask)] + __builtin_popcount(((1 << k) - 1) ^ mask));
            }
        }

        int64_t ans = INF;
        for (int mask = 0; mask < (1 << k); mask++) {
            ans = min(ans, dp[mask]);
        }

        m[i] = ans;
    }

    for (int i = 0; i < n; i++) {
        cout << m[i] << '\n';
    }

    return 0;
}