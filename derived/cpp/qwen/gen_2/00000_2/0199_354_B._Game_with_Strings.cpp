#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(auto &row: grid) cin >> row;
    
    // dp[r][c][0]: max a's for path ending at (r,c)
    // dp[r][c][1]: max b's for path ending at (r,c)
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));
    dp[1][1][grid[0][0] == 'a'] = 1;

    for(int r = 1; r <= n; ++r){
        for(int c = 1; c <= n; ++c){
            int a_val = grid[r-1][c-1] == 'a';
            int b_val = grid[r-1][c-1] == 'b';
            
            dp[r][c][0] = max(dp[r-1][c][0] + a_val, dp[r][c-1][0] + a_val);
            dp[r][c][1] = max(dp[r-1][c][1] + b_val, dp[r][c-1][1] + b_val);
        }
    }

    int a_count = dp[n][n][0];
    int b_count = dp[n][n][1];
    
    if(a_count > b_count) cout << "FIRST";
    else if(b_count > a_count) cout << "SECOND";
    else cout << "DRAW";
}