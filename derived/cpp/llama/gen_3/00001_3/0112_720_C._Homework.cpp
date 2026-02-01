#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    if (k > (n * m - 1) / 2) {
        cout << -1 << endl;
        return;
    }

    vector<string> ans(n, string(m, '.'));
    int x = 0, y = 0;
    while (k > 0) {
        if (x + 1 < n && y + 1 < m && k >= 4) {
            ans[x][y] = ans[x + 1][y] = ans[x][y + 1] = ans[x + 1][y + 1] = '*';
            k -= 4;
            x += 2;
            y += 2;
        } else if (x + 1 < n && k >= 1) {
            ans[x][y] = ans[x + 1][y] = '*';
            k -= 1;
            x += 2;
        } else if (y + 1 < m && k >= 1) {
            ans[x][y] = ans[x][y + 1] = '*';
            k -= 1;
            y += 2;
        } else {
            break;
        }
    }

    if (k > 0) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}