#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;

struct Edge {
    int to, weight;
};

struct Rule {
    int x, y, c;
};

int dp[1 << 18][18];
int n, m, k;
int a[18];
vector<Rule> rules;

int get_mask(vector<int> v) {
    int mask = 0;
    for (int x : v) {
        mask |= (1 << x);
    }
    return mask;
}

int solve(int mask, int last) {
    if (__builtin_popcount(mask) == m) {
        return 0;
    }

    if (dp[mask][last] != -1) {
        return dp[mask][last];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            int add = a[i];
            if (last != -1) {
                for (auto r : rules) {
                    if (r.x == last && r.y == i) {
                        add += r.c;
                        break;
                    }
                }
            }

            ans = max(ans, add + solve(mask | (1 << i), i));
        }
    }

    return dp[mask][last] = ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        rules.push_back({x, y, c});
    }

    memset(dp, -1, sizeof dp);

    cout << solve(0, -1) << endl;
}