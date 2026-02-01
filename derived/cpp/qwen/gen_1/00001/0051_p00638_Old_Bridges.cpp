#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n; cin >> n;
        if(n == 0) break;
        vector<int> treasures(n);
        vector<int> max_loads(n);
        for(int i=0; i<n; ++i){
            cin >> treasures[i] >> max_loads[i];
        }
        int total_treasure = 0;
        for(int treasure : treasures){
            total_treasure += treasure;
        }
        vector<int> dp(1 << n, 0);
        dp[0] = 1;
        for(int mask=1; mask<(1<<n); ++mask){
            for(int i=0; i<n; ++i){
                if(mask&(1<<i)){
                    int prev_mask = mask ^ (1 << i);
                    int prev_total = 0;
                    for(int j=0; j<n; ++j){
                        if(prev_mask & (1 << j)){
                            prev_total += treasures[j];
                        }
                    }
                    if(prev_total + treasures[i] <= max_loads[i]){
                        dp[mask] |= dp[prev_mask];
                    }
                }
            }
        }
        if(dp[(1<<n)-1]) cout << "Yes\n";
        else cout << "No\n";
    }
}