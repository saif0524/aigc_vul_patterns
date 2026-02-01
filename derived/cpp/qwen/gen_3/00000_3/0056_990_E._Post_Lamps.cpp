#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> blocked(m);
    for (int &x : blocked) cin >> x;
    vector<int> cost(k);
    for (int &x : cost) cin >> x;
    
    vector<bool> can_place(n, true);
    for (int x : blocked) can_place[x] = false;
    
    auto check = [&](int power) {
        vector<bool> covered(n + 1, false);
        for (int i = 0; i < n; ++i) {
            if (covered[i]) continue;
            if (!can_place[i]) continue;
            for (int j = i; j <= min(i + power, n); ++j) {
                covered[j] = true;
            }
        }
        return covered[n];
    };
    
    int ans = INT_MAX;
    for (int i = 0; i < k; ++i) {
        if (check(i + 1)) {
            ans = min(ans, cost[i]);
        }
    }
    
    if (ans == INT_MAX) cout << "-1\n";
    else cout << ans << "\n";
}