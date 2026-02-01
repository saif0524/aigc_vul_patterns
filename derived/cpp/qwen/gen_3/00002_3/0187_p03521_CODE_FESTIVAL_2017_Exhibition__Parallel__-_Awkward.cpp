#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2005;

int dp[MAXN][MAXN];
int par[MAXN];
int cnt[MAXN];
bool seen[MAXN];

int main(){
    int N;
    cin >> N;
    for(int i=2;i<=N;i++){
        cin >> par[i];
        cnt[par[i]]++;
    }
    
    dp[0][0] = 1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=i;j++){
            int sum = 0;
            for(int k=0;k<=cnt[i];k++){
                if(!seen[par[i]] || k==0){
                    sum = (sum + dp[i-1][j-k]) % MOD;
                }
            }
            if(cnt[i] > 0 && !seen[par[i]]){
                sum = (sum + dp[i-1][j-cnt[i]] * (cnt[i] - j)) % MOD;
            }
            dp[i][j] = sum;
        }
        if(i<N) seen[i] = true;
    }
    
    int ans = dp[N][0];
    for(int i=1;i<=N;i++){
        if(cnt[i] > 0){
            ans = (ans - dp[N][cnt[i]] + MOD) % MOD;
        }
    }
    
    cout << ans;
}