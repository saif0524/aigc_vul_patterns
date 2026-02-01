#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
#include <chrono>
#include <stack>
#include <string>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 25;
const int INF = 1e9;

int n;
int a[N][3];
int dp[1 << N][N * 50 + 1][3];

bool solve() {
    memset(dp, -INF, sizeof dp);
    dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int s = 0; s <= n * 50; s++) {
            if (dp[mask][s][0] == -INF && dp[mask][s][1] == -INF && dp[mask][s][2] == -INF) {
                continue;
            }

            int last = mask & (1 << n - 1) ? n - 1 : __builtin_ctz(mask);
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    continue;
                }

                for (int j = 0; j < 3; j++) {
                    for (int k = j + 1; k < 3; k++) {
                        int newS = s + a[i][j] + a[i][k];
                        int mask1 = mask | (1 << i);
                        dp[mask1][newS][j] = max(dp[mask1][newS][j], dp[mask][s][j]);
                        dp[mask1][newS][k] = max(dp[mask1][newS][k], dp[mask][s][k]);
                    }
                }
            }
        }
    }

    int ans = -INF;
    vi path;
    for (int i = 0; i < N * 50 + 1; i++) {
        if (dp[(1 << n) - 1][i][0] != -INF && dp[(1 << n) - 1][i][1] != -INF && dp[(1 << n) - 1][i][2] != -INF && dp[(1 << n) - 1][i][0] == dp[(1 << n) - 1][i][1] && dp[(1 << n) - 1][i][1] == dp[(1 << n) - 1][i][2] && dp[(1 << n) - 1][i][0] > ans) {
            ans = dp[(1 << n) - 1][i][0];
            for (int j = (1 << n) - 1, s = i; j > 0; ) {
                if (s > 0 && dp[j][s][0] == dp[j][s][1] && dp[j][s][2] == dp[j][s][1]) {
                    path.push_back(0);
                    path.push_back(1);
                    s -= a[__builtin_ctz(j)][0] + a[__builtin_ctz(j)][1];
                    j ^= 1 << __builtin_ctz(j);
                } else if (s > 0 && dp[j][s][0] == dp[j][s][2] && dp[j][s][2] == dp[j][s][1]) {
                    path.push_back(0);
                    path.push_back(2);
                    s -= a[__builtin_ctz(j)][0] + a[__builtin_ctz(j)][2];
                    j ^= 1 << __builtin_ctz(j);
                } else {
                    path.push_back(1);
                    path.push_back(2);
                    s -= a[__builtin_ctz(j)][1] + a[__builtin_ctz(j)][2];
                    j ^= 1 << __builtin_ctz(j);
                }
            }
            reverse(all(path));
        }
    }

    if (ans == -INF) {
        cout << "Impossible" << endl;
        return false;
    }

    for (int x : path) {
        if (x == 0) cout << "LM" << endl;
        if (x == 1) cout << "MW" << endl;
        if (x == 2) cout << "LW" << endl;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    rep(i, 0, n) {
        rep(j, 0, 3) {
            cin >> a[i][j];
        }
    }

    solve();

    return 0;
}