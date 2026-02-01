#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2010;

int dp[MAXN][MAXN];
vector<int> adj[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=2;i<=N;i++){
        int b;
        cin >> b;
        adj[b].push_back(i);
    }
    dp[0][0] = 1;
    for(int i=1;i<=N;i++){
        for(int mask=0;mask<(1<<N);mask++){
            if(dp[i-1][mask]){
                int j = __builtin_popcount(mask) + 1;
                for(int k=0;k<N;k++){
                    if(((mask>>k)&1)==0){
                        int new_mask = mask|(1<<k);
                        bool valid = true;
                        for(int &u : adj[j]){
                            if(((new_mask>>(u-1))&1)){
                                valid = false;
                            }
                        }
                        if(valid){
                            dp[i][new_mask] = (dp[i][new_mask] + dp[i-1][mask]) % MOD;
                        }
                    }
                }
            }
        }
    }
    cout << dp[N][(1<<N)-1] << "\n";
    return 0;
}