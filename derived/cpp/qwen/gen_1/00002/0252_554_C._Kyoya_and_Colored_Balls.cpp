#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    int k;
    cin >> k;
    vector<int> c(k);
    int total = 0;
    for(int &x : c){
        cin >> x;
        total += x;
    }
    vector<vector<long long>> dp(total + 1, vector<long long>(k + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= total; ++i){
        for(int j = 1; j <= k; ++j){
            if(c[j-1] > 0){
                for(int l = 0; l < j; ++l){
                    dp[i][j] = (dp[i][j] + dp[i-1][l]) % MOD;
                }
            }
        }
    }
    long long result = 0;
    for(int j = 1; j <= k; ++j){
        result = (result + dp[total][j]) % MOD;
    }
    cout << result;
}