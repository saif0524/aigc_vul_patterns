#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>

using namespace std;

const int MAXN = 300005;
const int MAXBIT = 20;

int n, q;
int a[MAXN];
bool dp[MAXN][MAXBIT];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(dp, false, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAXBIT; j++) {
            if (a[i] & (1 << j)) {
                dp[i][j] = true;
            }
        }
        for (int j = 1; j < i; j++) {
            if (a[j] == 0) {
                continue;
            }
            for (int k = 0; k < MAXBIT; k++) {
                if (dp[j][k] && (a[i] & (1 << k))) {
                    for (int t = 0; t < MAXBIT; t++) {
                        dp[i][t] |= dp[j][t];
                    }
                }
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        bool flag = false;
        for (int i = 0; i < MAXBIT; i++) {
            if (dp[y][i] && (a[x] & (1 << i))) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "Shi" << endl;
        } else {
            cout << "Fou" << endl;
        }
    }
    return 0;
}