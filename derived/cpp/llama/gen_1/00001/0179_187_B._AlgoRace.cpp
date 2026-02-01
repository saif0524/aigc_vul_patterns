#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max() / 2;

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(n)));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> dist[i][j][k];
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l < n; ++l) {
                    dist[i][j][l] = min(dist[i][j][l], dist[i][j][k] + dist[i][k][l]);
                }
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        int s, t, k;
        cin >> s >> t >> k;
        --s; --t;

        vector<vector<long long>> dp(n, vector<long long>(k + 1, INF));
        for (int j = 0; j < m; ++j) {
            dp[s][0] = min(dp[s][0], dist[j][s][t]);
        }

        for (int j = 1; j <= k; ++j) {
            for (int l = 0; l < n; ++l) {
                for (int p = 0; p < m; ++p) {
                    for (int q = 0; q < m; ++q) {
                        dp[l][j] = min(dp[l][j], dp[s][j - 1] + dist[p][s][l] + dist[q][l][t]);
                    }
                }
            }
        }

        long long ans = INF;
        for (int j = 0; j <= k; ++j) {
            ans = min(ans, dp[t][j]);
        }

        cout << ans << "\n";
    }

    return 0;
}