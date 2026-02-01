#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 40005;

int n, h[MAX_N], a[MAX_N], d[MAX_N], s[MAX_N];

bool cmp(int i, int j) {
    return s[i] > s[j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> h[i] >> a[i] >> d[i] >> s[i];
    }

    vector<int> order(n + 1);
    iota(order.begin(), order.end(), 0);
    sort(order.begin() + 1, order.end(), cmp);

    int res = 0;
    for (int t = 0; ; ++t) {
        for (int i : order) {
            if (i == 0) { // hero's turn
                if (t == 0) {
                    for (int j = 1; j <= n; ++j) {
                        if (h[j] > 0) {
                            h[j] -= max(a[0] - d[j], 0);
                            break;
                        }
                    }
                } else {
                    int maxDamage = 0, maxJ = -1;
                    for (int j = 1; j <= n; ++j) {
                        if (h[j] > 0 && max(a[0] - d[j], 0) > maxDamage) {
                            maxDamage = max(a[0] - d[j], 0);
                            maxJ = j;
                        }
                    }
                    if (maxJ != -1) {
                        h[maxJ] -= maxDamage;
                    }
                }
            } else { // enemy's turn
                if (h[0] > 0) {
                    h[0] -= max(a[i] - d[0], 0);
                    res += max(a[i] - d[0], 0);
                }
            }
        }

        bool heroAlive = h[0] > 0;
        bool enemiesAlive = false;
        for (int i = 1; i <= n; ++i) {
            if (h[i] > 0) {
                enemiesAlive = true;
                break;
            }
        }

        if (!heroAlive) {
            cout << -1 << '\n';
            return 0;
        }
        if (!enemiesAlive) {
            cout << res << '\n';
            return 0;
        }
    }

    return 0;
}