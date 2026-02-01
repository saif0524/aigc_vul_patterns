#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

const int MOD = 1e9 + 7;

ll n, p;
ll ans = 0;
ll colors[55];
vvi g;

ll pow_mod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return pow_mod(x, MOD - 2);
}

ll dp[55][55][2];

void solve(int pos, int cnt, int col) {
    if (pos == n) {
        if (cnt % 2 == p) ans = (ans + 1) % MOD;
        return;
    }
    if (dp[pos][cnt][col] != -1) return;
    dp[pos][cnt][col] = 1;
    if (colors[pos] == -1) {
        solve(pos + 1, cnt, col);
        solve(pos + 1, cnt + (1 - col), 1 - col);
    } else if (colors[pos] != -1) {
        solve(pos + 1, cnt + (1 - col) * (colors[pos] != col), colors[pos]);
    }
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> colors[i];
    solve(0, 0, 0);
    solve(0, 0, 1);
    cout << ans << endl;
    return 0;
}