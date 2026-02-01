#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<array<int, 4>> books(n);
    for(int i=0;i<n;i++){
        cin >> books[i][0] >> books[i][1] >> books[i][2];
        books[i][3] = i;
    }
    vector<vector<int>> dp(k+1, vector<int>(k+1, 1e9));
    dp[0][0] = 0;
    for(auto &book : books){
        for(int i=k;i>=0;i--){
            for(int j=k;j>=0;j--){
                if(i-book[1]>=0){
                    dp[i][j] = min(dp[i][j], dp[i-book[1]][j] + book[0]);
                }
                if(j-book[2]>=0){
                    dp[i][j] = min(dp[i][j], dp[i][j-book[2]] + book[0]);
                }
                if(i-book[1]>=0 && j-book[2]>=0){
                    dp[i][j] = min(dp[i][j], dp[i-book[1]][j-book[2]] + book[0]);
                }
            }
        }
    }
    int ans = 1e9;
    for(int i=k;i<=k;i++){
        for(int j=k;j<=k;j++){
            ans = min(ans, dp[i][j]);
        }
    }
    if(ans == 1e9){
        cout << -1;
    } else {
        cout << ans;
    }
}