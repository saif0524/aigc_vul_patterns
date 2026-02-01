#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin >> grid[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = (grid[0][0] == 'a') - (grid[0][0] == 'b');
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0] + ((grid[i][0] == 'a') - (grid[i][0] == 'b'));
        dp[0][i] = dp[0][i-1] + ((grid[0][i] == 'a') - (grid[0][i] == 'b'));
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + ((grid[i][j] == 'a') - (grid[i][j] == 'b'));
        }
    }
    int result = dp[n-1][n-1];
    if(result > 0) cout << "FIRST";
    else if(result < 0) cout << "SECOND";
    else cout << "DRAW";
}