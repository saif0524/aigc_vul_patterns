#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<pair<int, int>> coins;
    for(int i = 0; i < H; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < W; ++j){
            if(s[j] == '#'){
                coins.push_back({i, j});
            }
        }
    }
    
    int n = coins.size();
    int ans = 0;
    map<int, int> cnt;
    
    for(int i = 0; i < n; ++i){
        cnt.clear();
        for(int j = 0; j < n; ++j){
            if(i == j) continue;
            int dx = abs(coins[i].first - coins[j].first);
            int dy = abs(coins[i].second - coins[j].second);
            cnt[dx + dy]++;
        }
        for(const auto& c : cnt){
            int x = c.second;
            ans += x * (x-1) / 2;
        }
    }
    
    cout << ans;
}