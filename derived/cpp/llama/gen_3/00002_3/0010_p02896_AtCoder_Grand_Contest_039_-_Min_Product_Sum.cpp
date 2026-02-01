#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const int MAXN = 105;

ll dp[MAXN][MAXN][MAXN];
ll pre[MAXN][MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K, D;
    cin >> N >> M >> K >> D;

    dp[0][0][0] = 1;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= K; k++) {
                pre[i][j][k] = (pre[i][j][k - 1] + dp[i][j][k]) % D;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 1; k <= K; k++) {
                dp[i][j][k] = (dp[i][j][k] + pre[i - 1][j][k]) % D;
                dp[i][j][k] = (dp[i][j][k] + pre[i][j - 1][k]) % D;
                dp[i][j][k] = (dp[i][j][k] + (k - 1) * pre[i][j][k - 1]) % D;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= K; i++) {
        ans = (ans + dp[N][M][i]) % D;
    }

    cout << ans << '\n';

    return 0;
}