#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> ab(n);
    for(auto& [a,b]: ab) cin >> a >> b;
    
    int cur = 1;
    vector<int> dp(1,1);
    for(auto& [a, b]: ab){
        for(int i = 0; i < a; ++i){
            vector<int> newdp(cur + 1, 0);
            for(int j = 0; j <= cur; ++j){
                if(j > 0) newdp[j] = (newdp[j] + dp[j-1]) % MOD;
                newdp[j] = (newdp[j] + dp[j]) % MOD;
                if(j < cur) newdp[j] = (newdp[j] + dp[j+1]) % MOD;
            }
            dp = move(newdp);
            ++cur;
        }
        for(int i = 0; i < b; ++i){
            vector<int> newdp(cur - 1, 0);
            for(int j = 0; j < cur; ++j){
                if(j > 0) newdp[j-1] = (newdp[j-1] + dp[j-1]) % MOD;
                newdp[j-1] = (newdp[j-1] + dp[j]) % MOD;
                if(j < cur-1) newdp[j] = (newdp[j] + dp[j]) % MOD;
            }
            dp = move(newdp);
            --cur;
        }
    }
    int ans = 0;
    for(int x: dp) ans = (ans + x) % MOD;
    cout << ans;
}