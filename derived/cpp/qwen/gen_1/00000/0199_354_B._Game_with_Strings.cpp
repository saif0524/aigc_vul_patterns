#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> T(n);
    for(auto &s : T) cin >> s;
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = (T[0][0] == 'a') - (T[0][0] == 'b');
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            int val = (T[i][j] == 'a') - (T[i][j] == 'b');
            if(i) dp[i][j] = max(dp[i][j], dp[i-1][j] + val);
            if(j) dp[i][j] = max(dp[i][j], dp[i][j-1] + val);
        }
    if(dp[n-1][n-1] > 0) cout << "FIRST";
    else if(dp[n-1][n-1] < 0) cout << "SECOND";
    else cout << "DRAW";
}