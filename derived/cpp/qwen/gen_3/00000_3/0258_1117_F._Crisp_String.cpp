#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    vector<vector<int>> A(p, vector<int>(p));
    for(int i = 0; i < p; ++i){
        for(int j = 0; j < p; ++j){
            cin >> A[i][j];
        }
    }
    vector<int> cnt(26, 0);
    for(auto &c : s){
        cnt[c - 'a']++;
    }
    vector<int> dp(1 << p, n);
    dp[0] = 0;
    for(int mask = 0; mask < (1 << p); ++mask){
        for(int i = 0; i < p; ++i){
            if(cnt[i] == 0){
                continue;
            }
            if(mask & (1 << i)){
                continue;
            }
            int new_mask = mask | (1 << i);
            int can = 1;
            for(int j = 0; j < p; ++j){
                if((mask & (1 << j)) && !A[i][j]){
                    can = 0;
                    break;
                }
            }
            if(can){
                dp[new_mask] = min(dp[new_mask], dp[mask] - cnt[i]);
            }
        }
    }
    cout << dp[(1 << p) - 1] << "\n";
}