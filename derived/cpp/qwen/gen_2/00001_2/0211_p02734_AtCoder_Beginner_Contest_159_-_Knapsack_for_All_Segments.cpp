#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for(auto &a: A) cin >> a;

    vector<vector<int>> dp(N+1, vector<int>(S+1));
    dp[0][0] = 1;

    for(int i=1;i<=N;i++){
        for(int j=0;j<=S;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= A[i-1]){
                dp[i][j] = (dp[i][j] + dp[i-1][j-A[i-1]]) % MOD;
            }
        }
    }

    long long result = 0;
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            result = (result + dp[j][S] - dp[i-1][S] + MOD) % MOD;
        }
    }

    cout << result;
}