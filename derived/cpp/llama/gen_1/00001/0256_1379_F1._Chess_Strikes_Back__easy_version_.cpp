#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, m, q;
int g[200020][200020];
int col1[200020], col2[200020];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> q;
    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 1; j <= 2 * m; ++j) {
            g[i][j] = 1;
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        g[r][c] = 0;
        if ((r + c) % 2 == 0) {
            if (r % 2 == 1) {
                col1[c]++;
            } else {
                col2[c]++;
            }
        }

        bool yes = true;

        for (int c = 1; c <= 2 * m; ++c) {
            if (col1[c] > m) {
                yes = false;
                break;
            }
            if (col2[c] > m) {
                yes = false;
                break;
            }
        }

        if (yes) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}