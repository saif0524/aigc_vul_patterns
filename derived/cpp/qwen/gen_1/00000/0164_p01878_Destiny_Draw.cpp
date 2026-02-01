#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 45;
const int MAXT = 1000005;

int dp[MAXT][MAXN];
int ndp[MAXT][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K, C, T;
    cin >> N >> K >> C >> T;
    dp[0][1] = 1;
    for(int t = 0; t < T; ++t){
        for(int i = 1; i <= K; ++i){
            int a, b, ti;
            cin >> a >> b >> ti;
            if(t + ti <= T){
                for(int j = 1; j <= N; ++j){
                    ndp[t + ti][j] = (ndp[t + ti][j] + dp[t][j]) % MOD;
                }
                for(int j = 1; j <= N; ++j){
                    if(a <= j && j <= a + b - 1){
                        int newpos = j - a + 1;
                        ndp[t + ti][newpos] = (ndp[t + ti][newpos] + dp[t][j]) % MOD;
                    }
                }
            }
        }
        for(int j = 1; j <= N; ++j){
            dp[t+1][j] = ndp[t+1][j];
            ndp[t+1][j] = 0;
        }
    }
    cout << dp[T][C] << "\n";
}