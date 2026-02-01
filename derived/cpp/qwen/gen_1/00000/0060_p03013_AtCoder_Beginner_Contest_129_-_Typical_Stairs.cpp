#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int N, M;
    cin >> N >> M;
    vector<bool> broken(N, false);
    for(int i=0; i<M; i++){
        int a;
        cin >> a;
        broken[a] = true;
    }
    
    vector<long long> dp(N+1, 0);
    dp[0] = 1;
    for(int i=1; i<=N; i++){
        if(broken[i-1]){
            dp[i] = 0;
        } else {
            if(i-1 >= 0) dp[i] = (dp[i] + dp[i-1]) % MOD;
            if(i-2 >= 0) dp[i] = (dp[i] + dp[i-2]) % MOD;
        }
    }
    
    cout << dp[N] << endl;
    return 0;
}