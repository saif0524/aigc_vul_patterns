#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<ll> lengths(n);
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    vector<int> costs(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    vector<vector<ll>> dp(1 << n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = costs[i];
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        ll gcd = 0;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) > 0) {
                if (gcd == 0) {
                    gcd = lengths[i];
                } else {
                    gcd = __gcd(gcd, lengths[i]);
                }
            }
        }

        if (gcd == 1) {
            for (int i = 0; i < n; i++) {
                if (dp[mask][i] > 0) {
                    cout << dp[mask][i] << endl;
                    return 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                ll new_cost = dp[mask][i] + costs[i];
                if (dp[mask | (1 << i)][i] == 0 || dp[mask | (1 << i)][i] > new_cost) {
                    dp[mask | (1 << i)][i] = new_cost;
                }
            }
        }
    }

    cout << -1 << endl;
}