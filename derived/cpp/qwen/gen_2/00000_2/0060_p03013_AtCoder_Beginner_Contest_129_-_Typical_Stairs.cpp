#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<bool> broken(N, false);
    for(int i=0;i<M;i++){
        int a;
        cin >> a;
        broken[a] = true;
    }
    vector<long long> dp(N+1, 0);
    dp[0] = 1;
    for(int i=1;i<=N;i++){
        if(!broken[i]){
            dp[i] = (dp[i] + dp[i-1]) % MOD;
            if(i > 1) dp[i] = (dp[i] + dp[i-2]) % MOD;
        }
    }
    cout << dp[N] << "\n";
}