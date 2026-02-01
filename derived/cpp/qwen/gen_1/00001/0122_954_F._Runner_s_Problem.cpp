#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 10005;

int main(){
    int n;
    ll m;
    cin >> n >> m;
    vector<vector<ll>> obstacles(4, vector<ll>(m+1, 0));
    for(int i = 0; i < n; ++i){
        int a, l, r;
        cin >> a >> l >> r;
        obstacles[a][l] += 1;
        if(r + 1 <= m) obstacles[a][r + 1] -= 1;
    }
    for(int i = 1; i <= 3; ++i){
        for(ll j = 2; j <= m; ++j){
            obstacles[i][j] += obstacles[i][j-1];
        }
    }
    vector<ll> dp(3, 0);
    dp[1] = 1;
    for(ll j = 2; j <= m; ++j){
        vector<ll> new_dp(3, 0);
        for(int i = 0; i < 3; ++i){
            if(obstacles[i+1][j] == 0){
                new_dp[i] = dp[i];
                if(i > 0 && obstacles[i][j] == 0) new_dp[i] = (new_dp[i] + dp[i-1]) % MOD;
                if(i < 2 && obstacles[i+2][j] == 0) new_dp[i] = (new_dp[i] + dp[i+1]) % MOD;
            }
        }
        dp = new_dp;
    }
    cout << dp[1] << endl;
}