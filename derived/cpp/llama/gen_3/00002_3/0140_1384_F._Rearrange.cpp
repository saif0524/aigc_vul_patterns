#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 255;

int n, m;
int a[MAXN][MAXN];
int ans[MAXN][MAXN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    set<int> x, y;
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < m; j++) {
            mx = max(mx, a[i][j]);
        }
        x.insert(mx);
    }
    for (int j = 0; j < m; j++) {
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, a[i][j]);
        }
        y.insert(mx);
    }

    vector<int> vx, vy;
    for (auto it : x) {
        vx.push_back(it);
    }
    for (auto it : y) {
        vy.push_back(it);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());

    int p = 0, q = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (p < vx.size() && vx[p] == vy[q]) {
                ans[i][j] = vx[p];
                p++;
                q++;
            } else if (q < vy.size()) {
                ans[i][j] = vy[q];
                q++;
            } else {
                ans[i][j] = vx[p];
                p++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}