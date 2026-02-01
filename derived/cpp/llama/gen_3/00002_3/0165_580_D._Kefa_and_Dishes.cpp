#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> rules(n, vector<int>(n, 0));
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        rules[x - 1][y - 1] = c;
    }

    vector<vector<long long>> dp((1 << n), vector<long long>(n, -1));

    function<long long(int, int)> go = [&](int mask, int last) {
        if (__builtin_popcount(mask) == m) return 0;
        if (dp[mask][last] != -1) return dp[mask][last];

        long long max_val = 0;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                long long new_val = a[i] + go(mask | (1 << i), i);
                if (last != -1) new_val += rules[last][i];
                max_val = max(max_val, new_val);
            }
        }
        return dp[mask][last] = max_val;
    };

    cout << go(0, -1) << '\n';

    return 0;
}