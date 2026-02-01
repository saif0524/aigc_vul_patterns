#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> D(N);
    for(auto &d : D) cin >> d;
    vector<int> C(M);
    for(auto &c : C) cin >> c;
    
    vector<int> dp(N+1, 1e9);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        vector<int> new_dp(N+1, 1e9);
        for(int j = 0; j <= i; j++){
            int days_left = M - j;
            for(int k = 1; k <= days_left && i+k <= N; k++){
                new_dp[i+k] = min(new_dp[i+k], dp[j] + D[i] * C[j+k-1]);
            }
        }
        dp = move(new_dp);
    }
    cout << dp[N] << endl;
}