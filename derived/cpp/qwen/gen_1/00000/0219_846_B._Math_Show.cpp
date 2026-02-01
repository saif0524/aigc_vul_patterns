#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    long long M;
    cin >> n >> k >> M;
    vector<int> t(k);
    for(auto &x: t) cin >> x;
    
    vector<long long> dp(M+1, 0);
    
    for(int i=0; i<k; ++i){
        for(long long j=M; j>=t[i]; --j){
            dp[j] = max(dp[j], dp[j-t[i]] + 1);
        }
    }
    
    long long total_points = 0;
    for(int i=0; i<n; ++i){
        long long time_used = 0;
        int subtasks_done = 0;
        for(int j=0; j<k; ++j){
            if(time_used + t[j] <= M){
                time_used += t[j];
                subtasks_done++;
            }
        }
        total_points += subtasks_done;
        if(subtasks_done == k){
            total_points++;
        }
        M -= time_used;
    }
    
    long long max_points = total_points;
    for(long long j=0; j<=M; ++j){
        max_points = max(max_points, total_points - dp[j] + dp[M]);
    }
    
    cout << max_points;
}