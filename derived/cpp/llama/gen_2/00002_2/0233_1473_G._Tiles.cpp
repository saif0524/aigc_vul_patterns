#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    ll curr = 1;
    ll tiles = 1;
    vector<ll> dp;
    dp.push_back(curr);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < v[i].first; ++j) {
            vector<ll> ndp(tiles + 1);
            for (int k = 0; k < tiles; ++k) {
                ndp[k] = (ndp[k] + dp[k]) % MOD;
                ndp[k + 1] = (ndp[k + 1] + dp[k]) % MOD;
            }
            dp = ndp;
            tiles++;
        }
        for (int j = 0; j < v[i].second; ++j) {
            vector<ll> ndp(tiles - 1);
            for (int k = 0; k < tiles - 1; ++k) {
                ndp[k] = (ndp[k] + dp[k]) % MOD;
                ndp[k] = (ndp[k] + dp[k + 1]) % MOD;
            }
            dp = ndp;
            tiles--;
        }
    }

    ll ans = 0;
    for (auto i : dp) {
        ans = (ans + i) % MOD;
    }
    cout << ans << endl;

    return 0;
}