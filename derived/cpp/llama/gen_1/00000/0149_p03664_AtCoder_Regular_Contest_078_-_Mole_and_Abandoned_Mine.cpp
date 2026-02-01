#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;
const int MAXM = 1000;
int N, M;
int cost[MAXN][MAXN];
int dp[1 << MAXN][MAXN];
bool has_path[1 << MAXN][MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    memset(cost, -1, sizeof(cost));
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        cost[a][b] = cost[b][a] = c;
    }
    memset(has_path, 0, sizeof(has_path));
    for (int i = 0; i < N; i++) has_path[1 << i][i][i] = 1;
    for (int mask = 1; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (has_path[mask][i][j]) {
                    for (int k = 0; k < N; k++) {
                        if (!(mask & (1 << k)) && cost[j][k] != -1) {
                            has_path[mask | (1 << k)][i][k] = 1;
                        }
                    }
                }
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[1][0] = 0;
    int ans = INT_MAX;
    for (int mask = 1; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            if (dp[mask][i] != -1) {
                for (int j = 0; j < N; j++) {
                    if (cost[i][j] != -1 && !(mask & (1 << j))) {
                        int new_mask = mask | (1 << j);
                        int new_cost = dp[mask][i] + cost[i][j];
                        if (has_path[new_mask][0][N - 1] && (new_cost < ans)) {
                            ans = new_cost;
                        }
                        if (dp[new_mask][j] == -1 || dp[new_mask][j] > new_cost) dp[new_mask][j] = new_cost;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}