#include <bits/stdc++.h>

using namespace std;

int a[30005];
vector<vector<int>> ans;

void solve() {
    int n, c, q;
    cin >> n >> c >> q;
    ans.clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> tmp = a;
    tmp.insert(tmp.begin(), 0);
    ans.push_back(tmp);
    for (int len = 1; len <= c; len++) {
        for (int i = 1; i <= n - len; i++) {
            tmp = a;
            tmp.insert(tmp.begin(), 0);
            reverse(tmp.begin() + i, tmp.begin() + i + len);
            sort(ans.begin(), ans.end());
            if (find(ans.begin(), ans.end(), tmp) == ans.end()) {
                ans.push_back(tmp);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (y > ans.size()) {
            cout << -1 << "\n";
            continue;
        }
        cout << ans[y - 1][x] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}