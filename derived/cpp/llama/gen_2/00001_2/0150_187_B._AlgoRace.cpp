#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e14;

int n, m, r;
vector<vector<vector<int>>> dist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> r;
    dist = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(n)));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> dist[i][j][k];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < n; l++) {
                    dist[i][j][l] = min(dist[i][j][l], dist[i][j][k] + dist[i][k][l]);
                }
            }
        }
    }
    vector<vector<int>> minDist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                minDist[i][j] = min(minDist[i][j], dist[k][i][j]);
            }
        }
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(1001, INF)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j][0] = minDist[i][j];
        }
    }
    for (int k = 1; k <= 1000; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < n; l++) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i][l][k - 1] + minDist[l][j]);
                }
            }
        }
    }
    for (int i = 0; i < r; i++) {
        int s, t, k;
        cin >> s >> t >> k;
        s--; t--; k = min(k, 1000);
        cout << dp[s][t][k] << endl;
    }
    return 0;
}