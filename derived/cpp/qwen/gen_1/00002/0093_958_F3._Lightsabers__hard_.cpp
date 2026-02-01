#include <bits/stdc++.h>
using namespace std;

const int MOD = 1009;
const int MAXN = 200005;
const int MAXM = 1000;

int n, m, k;
int cnt[MAXM + 1];
int dp[MAXN][MAXM + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        cnt[c]++;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i][j-1];
            for(int x = 1; x <= cnt[j] && x <= i; x++){
                dp[i][j] = (dp[i][j] + dp[i-x][j-1]) % MOD;
            }
        }
    }
    cout << dp[k][m] << "\n";
}