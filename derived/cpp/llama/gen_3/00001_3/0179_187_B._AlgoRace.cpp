#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = 1e9;

void floyd(const vector<vector<vector<int>>>& d, vector<vector<int>>& dist, int n, int m) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int car = 0; car < m; car++) {
                    dist[i][j] = min(dist[i][j], d[car][i][k] + d[car][k][j]);
                }
            }
        }
    }
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<vector<int>>> d(m, vector<vector<int>>(n, vector<int>(n)));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> d[i][j][k];
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int car = 0; car < m; car++) {
                dist[i][j] = min(dist[i][j], d[car][i][j]);
            }
        }
    }

    floyd(d, dist, n, m);

    for (int i = 0; i < r; i++) {
        int s, t, k;
        cin >> s >> t >> k;
        s--, t--;

        int min_time = INF;
        vector<vector<int>> dp(n, vector<int>(n, INF));
        for (int j = 0; j < n; j++) {
            dp[s][j] = dist[s][j];
        }

        for (int j = 0; j < k; j++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    for (int z = 0; z < n; z++) {
                        dp[y][z] = min(dp[y][z], dp[x][y] + dist[y][z]);
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            min_time = min(min_time, dp[j][t]);
        }

        cout << min_time << endl;
    }

    return 0;
}