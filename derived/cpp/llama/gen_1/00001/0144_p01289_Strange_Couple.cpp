#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long double ld;

const int MAXN = 105;
const int INF = 1e9;

int n, s, t;
int q[MAXN];
vector<int> g[MAXN];
ld a[MAXN][MAXN];
ld f[MAXN][MAXN];
ld d[MAXN], p[MAXN];

void gau(ld* x) {
    ld f = 0.0;
    for (int i = 1; i <= n; ++i) {
        ld mn = INF;
        int v = 0;
        for (int j = 1; j <= n; ++j) {
            if (fabs(f[j]) > 1e-9 && (fabs(mn) < 1e-9 || f[j] < mn)) {
                mn = f[j];
                v = j;
            }
        }
        if (fabs(mn) < 1e-9) {
            cout << "impossible" << endl;
            return;
        }
        for (int j = 1; j <= n; ++j) {
            if (j == v) continue;
            f[j] = (f[j] * mn - f[v] * a[v][j]) / a[v][v];
        }
        f[v] = mn / a[v][v];
    }
    for (int i = 1; i <= n; ++i) {
        x[i] = f[i];
    }
}

int main() {
    while (cin >> n >> s >> t) {
        if (n == 0 && s == 0 && t == 0) break;
        for (int i = 1; i <= n; ++i) {
            cin >> q[i];
            g[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
                if (a[i][j] != 0) {
                    g[i].push_back(j);
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            d[i] = f[i][i] = a[i][i] = 1.0;
            p[i] = 0.0;
        }
        for (int i = 1; i <= n; ++i) {
            if (q[i]) {
                ld mn = INF;
                ld sm = 0.0;
                for (int j = 1; j <= n; ++j) {
                    if (a[i][j] != 0 && (fabs(mn) < 1e-9 || a[i][j] < mn)) {
                        mn = a[i][j];
                    }
                }
                for (int j = 1; j <= n; ++j) {
                    if (a[i][j] != 0 && a[i][j] == mn) {
                        sm += 1.0 / g[i].size();
                        a[i][j] = 0.0;
                        f[i][j] = -1.0 * sm;
                    } else {
                        a[i][j] = 0.0;
                        f[i][j] = 0.0;
                    }
                }
                a[i][i] = 1.0;
                d[i] = 0.0;
            } else {
                for (int j = 1; j <= n; ++j) {
                    if (a[i][j] != 0) {
                        a[i][j] = -1.0 / g[i].size();
                        f[i][j] = 1.0 / g[i].size();
                    } else {
                        a[i][j] = 0.0;
                        f[i][j] = 0.0;
                    }
                }
                a[i][i] = 1.0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = a[i][j];
            }
        }
        gau(d);
        for (int i = 1; i <= n; ++i) {
            if (q[i]) {
                ld mn = INF;
                ld sm = 0.0;
                for (int j = 1; j <= n; ++j) {
                    if (a[i][j] != 0 && (fabs(mn) < 1e-9 || a[i][j] < mn)) {
                        mn = a[i][j];
                    }
                }
                for (int j = 1; j <= n; ++j) {
                    if (a[i][j] != 0 && a[i][j] == mn) {
                        sm += d[j];
                    }
                }
                p[i] = mn + sm;
            } else {
                ld sm = 0.0;
                for (int j = 1; j <= n; ++j) {
                    if (a[i][j] != 0) {
                        sm += d[j] + a[i][j];
                    }
                }
                p[i] = sm;
            }
        }
        cout << fixed;
        cout.precision(8);
        cout << p[s] << endl;
    }
    return 0;
}