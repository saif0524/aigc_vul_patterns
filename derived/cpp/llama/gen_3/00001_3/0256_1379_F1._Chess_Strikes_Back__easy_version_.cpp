#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;

int n, m, q;
set<int> rowSets[400005], colSets[400005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;

    int total = n * m;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * m; j++) {
            if ((i + j) % 2 == 0) {
                if (i % 2 == 1) {
                    rowSets[i].insert(j);
                    colSets[j].insert(i);
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        rowSets[x].erase(y);
        colSets[y].erase(x);

        bool ok = true;
        for (int j = 1; j <= 2 * n; j += 2) {
            if (rowSets[j].size() > colSets[2 * m].size() - (j - 1) / 2) {
                ok = false;
                break;
            }
        }

        for (int j = 2; j <= 2 * m; j += 2) {
            if (colSets[j].size() > rowSets[2 * n].size() - (j - 2) / 2) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}