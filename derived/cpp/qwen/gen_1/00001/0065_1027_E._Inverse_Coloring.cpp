#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 501;

int n, k;
int dp[MAXN][2];
bool valid[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    if(n == 1 && k == 1){
        cout << 0;
        return 0;
    }
    dp[1][0] = dp[1][1] = 2;
    for(int i = 2; i <= n; i++){
        dp[i][0] = (1LL * dp[i-1][0] * (dp[i-1][0] + dp[i-1][1])) % MOD;
        dp[i][1] = (1LL * dp[i-1][1] * (dp[i-1][0] + dp[i-1][1])) % MOD;
    }
    int ans = (dp[n][0] + dp[n][1]) % MOD;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n - i + 1; j++){
            for(int l = 1; l <= n; l++){
                valid[j][l] = 1;
                valid[j+i-1][l] = 1;
            }
            for(int l = 2; l <= n - i + 1; l++){
                bool can = 1;
                for(int m = j; m <= j + i - 1; m++){
                    if(valid[m][l-1] || valid[m][l+i-1]){
                        can = 0;
                        break;
                    }
                }
                if(can){
                    int cnt = (dp[i][0] + dp[i][1]) % MOD;
                    for(int m = j; m <= j + i - 1; m++){
                        valid[m][l] = 1;
                        valid[m][l+i-1] = 1;
                    }
                    for(int m = j; m <= j + i - 1; m++){
                        for(int o = l; o <= l + i - 1; o++){
                            if(!valid[m][o]){
                                can = 0;
                                break;
                            }
                        }
                        if(!can) break;
                    }
                    if(can){
                        ans = (ans - (1LL * cnt * cnt) % MOD + MOD) % MOD;
                    }
                    for(int m = j; m <= j + i - 1; m++){
                        valid[m][l] = 0;
                        valid[m][l+i-1] = 0;
                    }
                }
            }
            for(int l = 1; l <= n; l++){
                valid[j][l] = 0;
                valid[j+i-1][l] = 0;
            }
        }
    }
    cout << ans;
}