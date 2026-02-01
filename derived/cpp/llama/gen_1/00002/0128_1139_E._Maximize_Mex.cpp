#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int mod = 998244353;

int n, m;
vector<int> p, c;
vector<vector<int>> clubs;

void solve() {
    cin >> n >> m;
    p.resize(n);
    c.resize(n);
    for (int &x : p) cin >> x;
    for (int &x : c) cin >> x, --x;
    clubs.resize(m);
    for (int i = 0; i < n; ++i) clubs[c[i]].push_back(i);
    int d;
    cin >> d;
    vector<bool> left(n);
    for (int i = 0; i < d; ++i) {
        int x;
        cin >> x;
        --x;
        left[x] = true;
        for (int j = 0; j < m; ++j) {
            if (find(clubs[j].begin(), clubs[j].end(), x) != clubs[j].end()) {
                auto it = find(clubs[j].begin(), clubs[j].end(), x);
                clubs[j].erase(it);
            }
        }
        int ans = 0;
        vector<int> vis(clubs.size(), 0);
        while (true) {
            bool found = false;
            for (int j = 0; j < m; ++j) {
                if (vis[j] < clubs[j].size() && !left[clubs[j][vis[j]]]) {
                    found = true;
                    break;
                }
            }
            if (!found) break;
            vector<int> cur;
            for (int j = 0; j < m; ++j) {
                if (vis[j] < clubs[j].size() && !left[clubs[j][vis[j]]]) {
                    cur.push_back(p[clubs[j][vis[j]]]);
                }
            }
            sort(cur.begin(), cur.end());
            int mex = 0;
            for (int x : cur) {
                if (x == mex) ++mex;
            }
            ans = max(ans, mex);
            int minval = inf;
            for (int j = 0; j < m; ++j) {
                if (vis[j] < clubs[j].size() && !left[clubs[j][vis[j]]]) {
                    minval = min(minval, p[clubs[j][vis[j]]]);
                }
            }
            for (int j = 0; j < m; ++j) {
                if (vis[j] < clubs[j].size() && !left[clubs[j][vis[j]]] && p[clubs[j][vis[j]]] == minval) {
                    ++vis[j];
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}