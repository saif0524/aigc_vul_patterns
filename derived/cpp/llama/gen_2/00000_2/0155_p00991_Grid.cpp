#include <iostream>
using namespace std;

const int MODE = 1e9 + 7;
const int MAXN = 1e3 + 5;

int f[MAXN][MAXN], r, c, a1, a2, b1, b2;

void update(int& x, int y) {
    x += y;
    if (x >= MODE) {
        x -= MODE;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> a1 >> a2 >> b1 >> b2;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            f[i][j] = 0;
        }
    }

    f[a1][a2] = 1;

    for (int k = 0; k < abs(b1 - a1) + abs(b2 - a2); k++) {
        int g[MAXN][MAXN];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                g[i][j] = 0;
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                update(g[(i + 1) % r][j], f[i][j]);
                update(g[(i - 1 + r) % r][j], f[i][j]);
                update(g[i][(j + 1) % c], f[i][j]);
                update(g[i][(j - 1 + c) % c], f[i][j]);
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                f[i][j] = g[i][j];
            }
        }
    }

    cout << f[b1][b2] << endl;

    return 0;
}