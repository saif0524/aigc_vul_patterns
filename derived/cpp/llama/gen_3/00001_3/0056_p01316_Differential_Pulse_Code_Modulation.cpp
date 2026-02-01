#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 20010;
const int MAXM = 17;

int n, m, C[MAXM];
int x[MAXN];
int y[MAXN];
int f[MAXN][MAXM];

void solve() {
    cin >> n >> m;
    if (n == 0 && m == 0) {
        exit(0);
    }

    for (int i = 0; i < m; i++) {
        cin >> C[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i <= m; i++) {
        f[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = y[i - 1] + C[j];
            tmp = min(max(tmp, 0), 255);
            f[i][j] = (x[i] - tmp) * (x[i] - tmp);
        }

        int minVal = 1e9;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                int t = f[i - 1][k] + f[i][j];
                minVal = min(minVal, t);
            }
        }

        cout << minVal << endl;
    }
}

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}