#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;
ll satisfaction[19];
vector<pair<int, ll>> rules[19];
ll dp[1 << 18], last[1 << 18];

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> satisfaction[i];
    for(int i = 0; i < k; i++){
        int x, y; ll c;
        cin >> x >> y >> c;
        x--, y--;
        rules[x].emplace_back(y, c);
    }
    for(int mask = 0; mask < (1 << n); mask++){
        if(__builtin_popcount(mask) > m) continue;
        for(int last_eaten = 0; last_eaten < n; last_eaten++){
            if(mask & (1 << last_eaten)){
                int prev_mask = mask ^ (1 << last_eaten);
                if(prev_mask == 0){
                    dp[mask] = max(dp[mask], satisfaction[last_eaten]);
                }
                else{
                    ll current_satisfaction = dp[prev_mask] + satisfaction[last_eaten];
                    for(auto [next, bonus] : rules[last_eaten]){
                        if(prev_mask & (1 << next)){
                            current_satisfaction += bonus;
                        }
                    }
                    dp[mask] = max(dp[mask], current_satisfaction);
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
}