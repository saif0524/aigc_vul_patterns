#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<bool>> grid(H, vector<bool>(W, false));
    for(int i = 0; i < H; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < W; ++j){
            grid[i][j] = (s[j] == '#');
        }
    }
    vector<pair<int, int>> coins;
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(grid[i][j]){
                coins.emplace_back(i, j);
            }
        }
    }
    int n = coins.size();
    map<int, vector<pair<int, int>>> dist_map;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int dist = abs(coins[i].first - coins[j].first) + abs(coins[i].second - coins[j].second);
            dist_map[dist].emplace_back(i, j);
        }
    }
    long long ans = 0;
    for(const auto& [dist, pairs] : dist_map){
        map<int, int> count;
        for(const auto& [a, b] : pairs){
            count[a]++;
            count[b]++;
        }
        for(const auto& [a, cnt] : count){
            long long x = cnt;
            ans += (x * (x - 1) / 2) * (n - cnt);
        }
    }
    cout << ans / 3 << endl;
}