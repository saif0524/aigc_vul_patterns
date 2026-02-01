#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<unordered_set<int>> friends(n);
    vector<int> ans(m, 0);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        friends[x].insert(y);
        friends[y].insert(x);
        vector<int> dp(n, 0);
        for(int j = 0; j < n; j++){
            int cnt = 0;
            for(auto &f : friends[j]){
                if(friends[f].size() >= k){
                    cnt++;
                }
            }
            if(cnt >= k){
                dp[j] = 1;
            }
        }
        for(int j = 0; j < n; j++){
            if(dp[j] == 1){
                for(auto &f : friends[j]){
                    dp[f] = max(dp[f], 1);
                }
            }
        }
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += dp[j];
        }
        ans[i] = sum;
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << "\n";
    }
}