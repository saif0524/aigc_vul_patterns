#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int MAXBITS = 20;

int n, q;
int a[MAXN];
bool dp[MAXN][MAXBITS];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAXBITS; j++) {
            if ((a[i] >> j) & 1) {
                dp[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAXBITS; j++) {
            if (dp[i][j]) {
                for (int k = i + 1; k <= n; k++) {
                    if ((a[k] >> j) & 1) {
                        for (int l = 0; l < MAXBITS; l++) {
                            dp[k][l] = dp[k][l] || dp[i][l];
                        }
                    }
                }
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        bool reachable = false;
        for (int i = 0; i < MAXBITS; i++) {
            if (dp[y][i] && ((a[x] >> i) & 1)) {
                reachable = true;
                break;
            }
        }
        cout << (reachable ? "Shi" : "Fou") << '\n';
    }

    return 0;
}