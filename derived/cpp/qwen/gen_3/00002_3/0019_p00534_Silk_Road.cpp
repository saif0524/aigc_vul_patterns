#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> D(N);
    vector<int> C(M);
    for(int i=0;i<N;i++) cin >> D[i];
    for(int i=0;i<M;i++) cin >> C[i];
    
    vector<vector<int>> dp(N+1, vector<int>(M+1, INT_MAX));
    dp[0][0] = 0;
    
    for(int city=1; city <=N; city++){
        for(int day=1; day<=M; day++){
            dp[city][day] = dp[city][day-1];
            for(int prev_day = 0; prev_day < day; prev_day++){
                if(dp[city-1][prev_day] != INT_MAX){
                    dp[city][day] = min(dp[city][day], dp[city-1][prev_day] + D[city-1] * C[day-1]);
                }
            }
        }
    }
    int result = INT_MAX;
    for(int day=1; day<=M; day++){
        result = min(result, dp[N][day]);
    }
    cout << result;
}