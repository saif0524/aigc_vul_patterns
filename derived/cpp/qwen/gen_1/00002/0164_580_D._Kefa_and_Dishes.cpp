#include <bits/stdc++.h>
using namespace std;

int n, m, k;
long long a[20];
vector<pair<int, long long>> rules[20];
long long dp[1 << 18][20];

long long solve(int mask, int last) {
    if (__builtin_popcount(mask) == m) return 0;
    long long &ret = dp[mask][last];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) {
            long long cur = a[i] + solve(mask | (1 << i), i);
            for (auto &[y, c] : rules[i]) {
                if (y == last) cur += c;
            }
            ret = max(ret, cur);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++){
        int x, y;
        long long c;
        cin >> x >> y >> c;
        x--; y--;
        rules[x].emplace_back(y, c);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n) << "\n";
}