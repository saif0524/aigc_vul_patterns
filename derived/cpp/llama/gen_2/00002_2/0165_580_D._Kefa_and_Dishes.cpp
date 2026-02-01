#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_N = 18;
const long long INF = LLONG_MAX;

long long dp[1 << MAX_N][MAX_N];
long long a[MAX_N];
long long rules[MAX_N][MAX_N];

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        rules[x][y] = c;
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -INF;
        }
    }

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = a[i];
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int last = 0; last < n; last++) {
            if (dp[mask][last] == -INF) {
                continue;
            }

            for (int next = 0; next < n; next++) {
                if ((mask & (1 << next))!= 0) {
                    continue;
                }

                int newMask = mask | (1 << next);
                long long newValue = dp[mask][last] + a[next] + rules[last][next];
                dp[newMask][next] = max(dp[newMask][next], newValue);
            }
        }
    }

    long long ans = -INF;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) == m) {
            for (int last = 0; last < n; last++) {
                ans = max(ans, dp[mask][last]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}