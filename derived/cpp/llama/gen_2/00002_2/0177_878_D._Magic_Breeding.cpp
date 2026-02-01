#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> b;
    b = a;

    int cnt = k;
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        x--; y--;

        if (t == 1) {
            vector<int> c(n);
            for (int j = 0; j < n; j++) {
                c[j] = max(b[x][j], b[y][j]);
            }
            b.push_back(c);
            cnt++;
        } else if (t == 2) {
            vector<int> c(n);
            for (int j = 0; j < n; j++) {
                c[j] = min(b[x][j], b[y][j]);
            }
            b.push_back(c);
            cnt++;
        } else {
            cout << b[x][y] << endl;
        }
    }

    return 0;
}