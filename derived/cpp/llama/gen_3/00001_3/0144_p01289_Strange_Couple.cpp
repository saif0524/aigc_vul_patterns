#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAXN = 105;
const double EPS = 1e-8;

int n, s, t;
int q[MAXN];
int a[MAXN][MAXN];
double f[MAXN];
double d[MAXN];
int deg[MAXN];

void solve() {
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        f[i] = 0;
        d[i] = 0;
        deg[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] > 0) {
                deg[i]++;
            }
        }
    }

    queue<int> q;
    q.push(t);
    f[t] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++) {
            if (a[u][v] > 0) {
                if (f[v] == 0) {
                    q.push(v);
                }
                f[v] = 1;
            }
        }
    }

    if (f[s] == 0) {
        cout << "impossible" << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (f[i] == 0) {
            continue;
        }
        if (i == t) {
            continue;
        }
        if (q[i] == 1) {
            int cnt = 0;
            double sum = 0;
            for (int j = 1; j <= n; j++) {
                if (a[i][j] > 0 && f[j] == 1) {
                    cnt++;
                    sum += a[i][j];
                }
            }
            for (int j = 1; j <= n; j++) {
                if (a[i][j] > 0 && f[j] == 1) {
                    d[j] += d[i] + a[i][j] - sum / cnt;
                }
            }
        } else {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] > 0 && f[j] == 1) {
                    d[j] += d[i] + a[i][j];
                }
            }
        }
    }

    cout << fixed << setprecision(8) << d[s] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        solve();
        if (cin.peek() == '0') {
            break;
        }
    }

    return 0;
}