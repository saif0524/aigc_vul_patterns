#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 110;

int main() {
    int a, b, k, t;
    cin >> a >> b >> k >> t;
    
    int dp[MAXN][2 * MAXN * 1001] = {0};
    int ndp[MAXN][2 * MAXN * 1001] = {0};
    
    dp[0][a - b + 100 * k * t] = 1;
    
    for(int i = 1; i <= t; i++) {
        for(int j = 0; j <= 2 * k; j++) {
            for(int s = 0; s <= 2 * k * t * 2; s++) {
                if(dp[j][s] == 0) continue;
                for(int md = -k; md <= k; md++) {
                    for(int ld = -k; ld <= k; ld++) {
                        ndp[j + (md > ld)][s + md - ld] = (ndp[j + (md > ld)][s + md - ld] + 1LL * dp[j][s] * dp[1][0]) % MOD;
                    }
                }
            }
        }
        for(int j = 0; j <= t; j++) {
            for(int s = 0; s <= 2 * k * t * 2; s++) {
                dp[j][s] = ndp[j][s];
                ndp[j][s] = 0;
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= t; i++) {
        for(int s = k * t * 2; s <= 2 * k * t * 2; s++) {
            ans = (ans + dp[i][s]) % MOD;
        }
    }
    
    cout << ans << endl;
    return 0;
}