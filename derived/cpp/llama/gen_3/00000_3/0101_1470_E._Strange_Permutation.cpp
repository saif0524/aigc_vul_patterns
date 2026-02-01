#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int n, c, q;
    cin >> n >> c >> q;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    set<vector<int>> perms;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            if (r - l <= c) {
                vector<int> perm = p;
                reverse(perm.begin() + l, perm.begin() + r + 1);
                perms.insert(perm);
            }
        }
    }

    vector<vector<int>> sortedPerms(perms.begin(), perms.end());

    for (int i = 0; i < q; ++i) {
        int idx, j;
        cin >> idx >> j;
        --idx;
        --j;
        if (j >= sortedPerms.size()) {
            cout << -1 << '\n';
        } else {
            cout << sortedPerms[j][idx] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}