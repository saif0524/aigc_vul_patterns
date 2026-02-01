#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    int N, M;
    cin >> N >> M;
    vector<bool> broken(N+1, false);
    for(int i = 0; i < M; ++i){
        int a;
        cin >> a;
        broken[a] = true;
    }
    vector<long long> dp(N+1, 0);
    dp[0] = 1;
    if(!broken[1]) dp[1] = 1;
    for(int i = 2; i <= N; ++i){
        if(broken[i]) continue;
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    cout << dp[N];
}