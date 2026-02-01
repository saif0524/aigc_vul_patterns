#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    set<int> rows;
    set<int> cols;
    map<int, set<int>> rowMap;
    map<int, set<int>> colMap;

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        rows.insert(r);
        cols.insert(c);
        rowMap[r].insert(c);
        colMap[c].insert(r);
    }

    if (rows.size() == n || cols.size() == m) {
        cout << 0 << endl;
        return;
    }

    int ans = 0;
    for (auto& row : rowMap) {
        if (row.second.size() == m) {
            ans++;
        }
    }

    for (auto& col : colMap) {
        if (col.second.size() == n) {
            ans++;
        }
    }

    if (ans == 0) {
        ans = min(rows.size(), cols.size());
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}