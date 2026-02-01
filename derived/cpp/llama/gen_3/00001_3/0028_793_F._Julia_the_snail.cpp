#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, m, q;
int ropes[MAXN];
int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        ropes[r] = max(ropes[r], l);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = i; j <= n; j++) {
            if (ropes[j] >= i) {
                dp[i] = max(dp[i], j);
            }
        }
    }

    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = x;
        for (int i = x; i <= y; i++) {
            if (dp[i] <= y) {
                ans = max(ans, dp[i]);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}