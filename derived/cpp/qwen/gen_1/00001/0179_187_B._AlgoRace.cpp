#include <bits/stdc++.h>
using namespace std;

const int N = 61;
const int M = 61;
const int INF = 1e9;

int n, m, r;
int dist[M][N][N];
int dp[N][N][M];

void floyd_warshall(int k) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j][0] = dist[k][i][j];
        }
    }
    for (int k = 1; k <= m; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int l = 1; l <= n; ++l) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i][l][k-1] + dist[k][l][j]);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> r;
    for(int k = 1; k <= m; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> dist[k][i][j];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 0; k <= m; k++){
                dp[i][j][k] = INF;
            }
        }
    }
    for(int k = 1; k <= m; k++){
        floyd_warshall(k);
    }
    for(int rr = 0; rr < r; rr++){
        int si, ti, ki;
        cin >> si >> ti >> ki;
        int ans = INF;
        for(int km = 0; km <= m && km <= ki; km++){
            ans = min(ans, dp[si][ti][km]);
        }
        cout << ans << "\n";
    }
}