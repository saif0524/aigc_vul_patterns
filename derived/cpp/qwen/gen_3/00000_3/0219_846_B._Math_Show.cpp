#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    long long M;
    cin >> n >> k >> M;
    vector<int> t(k);
    for(auto &x: t) cin >> x;
    vector<vector<long long>> dp(n+1, vector<long long>(M+1, 0));
    for(int i=1; i<=n; i++){
        for(long long j=0; j<=M; j++){
            for(int l=0; l<k; l++){
                if(j + t[l] <= M){
                    dp[i][j+t[l]] = max(dp[i][j+t[l]], dp[i][j] + 1);
                }
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    long long ans = 0;
    for(long long j=0; j<=M; j++){
        int tasks_completed = 0;
        long long points = 0;
        for(int i=0; i<k; i++){
            int cnt = 0;
            for(int l=0; l<n; l++){
                if(dp[l+1][j] >= i+1){
                    cnt++;
                }
            }
            points += cnt;
            if(cnt == n){
                tasks_completed++;
            }
        }
        ans = max(ans, points + tasks_completed);
    }
    cout << ans;
}