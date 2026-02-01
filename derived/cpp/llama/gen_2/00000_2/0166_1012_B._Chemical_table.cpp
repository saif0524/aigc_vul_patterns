#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<bool>> have(n, vector<bool>(m, false));
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        have[r - 1][c - 1] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = 0; j < m; ++j) {
            if (have[i][j]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            ans++;
        }
    }

    for (int i = 0; i < m; ++i) {
        bool flag = false;
        for (int j = 0; j < n; ++j) {
            if (have[j][i]) {
                flag = true;
                break;
            }
        }
        if (!flag && ans > 0) {
            ans--;
        }
    }

    cout << ans << endl;
    return 0;
}