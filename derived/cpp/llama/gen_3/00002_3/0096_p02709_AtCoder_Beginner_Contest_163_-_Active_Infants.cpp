#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll dp[2001][2001];

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i] * i + a[i] * (n - 1 - i));
    }

    auto solve = [&](auto &solve, int i, int j, int sum, int vis) {
        if (j == n) {
            return sum;
        }

        if (dp[i][vis]!= -1) {
            return dp[i][vis];
        }

        ll mx = 0;
        for (int k = 0; k < n; k++) {
            if (!(vis & (1 << k))) {
                mx = max(mx, solve(solve, (i + 1) % n, j + 1, sum + a[k] * abs(k - j), vis | (1 << k)));
            }
        }

        return dp[i][vis] = mx;
    };

    cout << solve(solve, 0, 0, 0, 0);

    return 0;
}