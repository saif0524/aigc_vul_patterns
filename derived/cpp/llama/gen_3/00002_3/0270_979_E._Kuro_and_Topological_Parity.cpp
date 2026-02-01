#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 55;

int dp[2][MAX_N][MAX_N][2];
int n, p;
int color[MAX_N];

void add(int &x, int y) {
    x = (x + y) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < 2; k++) {
                for (int m = 0; m < 2; m++) {
                    if (dp[0][j][k][m]) {
                        if (color[i] == -1) {
                            add(dp[1][j][1 - k][m], dp[0][j][k][m]);
                            add(dp[1][j + 1][k][m], dp[0][j][k][m]);
                        } else if (color[i] == 0) {
                            add(dp[1][j][1 - k][m], dp[0][j][k][m]);
                        } else {
                            add(dp[1][j + 1][k][m], dp[0][j][k][m]);
                        }
                    }
                }
            }
        }
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < 2; k++) {
                for (int m = 0; m < 2; m++) {
                    add(dp[0][j][k][m], dp[1][j][k][m]);
                    dp[1][j][k][m] = 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            add(ans, dp[0][i][j][p]);
        }
    }
    cout << ans << endl;
    return 0;
}