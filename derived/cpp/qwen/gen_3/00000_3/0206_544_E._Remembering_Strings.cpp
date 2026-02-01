#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(auto &str : s) cin >> str;
    vector<vector<int>> cost(n, vector<int>(m));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> cost[i][j];
        }
    }

    int ans = INT_MAX;
    for(int mask = 0; mask < (1 << (n * m)); ++mask){
        vector<vector<int>> cnt(m, vector<int>(26, 0));
        vector<int> chosen(n, -1);
        bool valid = true;
        for(int i=0; i<n && valid; ++i){
            for(int j=0; j<m; ++j){
                if(mask & (1 << (i * m + j))){
                    cnt[j][s[i][j] - 'a']++;
                    if(chosen[i] != -1) {valid = false; break;}
                    chosen[i] = j;
                }
            }
        }
        if(!valid) continue;
        for(int j=0; j<m && valid; ++j){
            int sum = 0, max_cnt = 0;
            for(int k=0; k<26; ++k){
                if(cnt[j][k] > 1) {valid = false; break;}
                sum += cnt[j][k];
                max_cnt = max(max_cnt, cnt[j][k]);
            }
            if(sum > 1 && max_cnt != 1) valid = false;
        }
        if(!valid) continue;
        int current_cost = 0;
        for(int i=0; i<n; ++i){
            if(chosen[i] != -1){
                current_cost += cost[i][chosen[i]];
            }
        }
        ans = min(ans, current_cost);
    }
    cout << ans;
}